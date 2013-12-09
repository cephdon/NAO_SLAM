/*
 * @(#)		main.cpp
 * @version	1.4
 * @autor	C. Rouvière
 */

 /**
 * Programme d'exploitation des images par OpenCV
 *	- Reconstitution 3D du corps d'un NAO
 */

#include "../Gui.h"
#include "../Flux_cam.h"
#include "../Body.h"

using namespace std;

int main(){

	char key = 'a';				// clef de contrôle du programme
	Flux_cam flux(-1, 40, 1, 3, 1);		// initialisation du flux webcam (/dev/video0)
	Gui gui;				// IHM
	Body body;

	// boucle d'exécution : appuyer sur 'q' pour quitter
	while(key != 'q'){
		key = flux.Get_key();
		// mettre à jour les images du flux
		flux.Update();

		body.Set_img(flux.Get_cam());
		body.Detecter_tete();
		body.Detecter_epaule_gauche();
		body.Detecter_epaule_droite();
		body.Detecter_coude_gauche();
		body.Detecter_coude_droit();
		body.Detecter_main_gauche();
		body.Detecter_main_droite();
		body.Detecter_pied_gauche();
		body.Detecter_pied_droit();
		gui.Afficher_image("video", flux.Get_cam());

		std::vector <cv::Point2f> liste1;
		std::vector <cv::Point2f> liste2;
		liste1.push_back(body.Get_Head());
		liste2.push_back(body.Get_L_shoulder());
		liste1.push_back(body.Get_Head());
		liste2.push_back(body.Get_R_shoulder());
		liste1.push_back(body.Get_L_shoulder());
		liste2.push_back(body.Get_L_elbow());
		liste1.push_back(body.Get_R_shoulder());
		liste2.push_back(body.Get_R_elbow());
		liste1.push_back(body.Get_L_elbow());
		liste2.push_back(body.Get_L_hand());
		liste1.push_back(body.Get_R_elbow());
		liste2.push_back(body.Get_R_hand());
		gui.Ajouter_vecteurs("test", flux.Get_cam(), liste1, liste2);
	}


	return 0;

}
