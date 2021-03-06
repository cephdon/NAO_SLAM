/*
 * @(#)		nao_pseudo3d.cpp
 * @version	1.4
 * @autor	C. Rouvière
 */

 /**
 * Programme d'exploitation des images par OpenCV
 *	- Détection et reliage de blobs : détection d'un nao avec une seule couleur
 */

#include <opencv/cv.h>

#include "../../Gui.h"
#include "../../Flux_cam.h"
#include "../../Blobs.h"

using namespace std;

int main(){

	char key = 'a';				// clef de contrôle du programme
	Flux_cam flux(-1, 40, 1, 3, 1);		// initialisation du flux webcam (/dev/video0)
	Blobs blobs;				// séparateur de blobs
	Gui gui;				// IHM
	gui.Creer_trackbar_HSV_sep("Separateur");

	// boucle d'exécution : appuyer sur 'q' pour quitter
	while(key != 'q'){
		key = flux.Get_key();
		// mettre à jour les images du flux
		flux.Update();
		// séparer les blobs mouse
		blobs.Set_img(flux.Get_prev());
		blobs.Definir_limites_separation(gui.Get_HSV_bound());
		blobs.Separer();
		blobs.Trouver_blobs();
		// relier les points
		std::vector <cv::Point2i> points = blobs.Get_mc();
		std::vector <cv::Point2i> pts1, pts2;
		for(size_t i = 0; i < points.size(); i++){
			for(size_t j = 0; j < points.size(); j++){
				if(i != j){
					pts1.push_back(points[i]);
					pts2.push_back(points[j]);
				}
			}
		}
		// afficher le résultat
		gui.Afficher_image("Video", flux.Get_prev());
		gui.Ajouter_vecteurs("Video pseudo3D", blobs.Get_img_blobs(), pts1, pts2);		
	}


	return 0;

}
