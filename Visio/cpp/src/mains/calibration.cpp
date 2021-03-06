/*
 * @(#)		calibration.cpp
 * @version	1.4
 * @autor	C. Rouvière
 */

 /**
 * Programme d'exploitation des images par OpenCV
 *	- Calibration de caméra
 */

#include "../Gui.h"
#include "../Flux_cam.h"
#include "../Calibrate.h"

using namespace std;

int main(){

	char key = 'a';				// clef de contrôle du programme
	Flux_cam flux(2, 40, 1, 3, 1);		// initialisation du flux webcam (/dev/video0)
	Gui gui;				// IHM
	Calibrate calib(cv::Size(10, 7));
	int nb_calib = 0;

	// boucle d'exécution : appuyer sur 'q' pour quitter
	while(key != 'q'){
		key = flux.Get_key();
		flux.Update();
		if(nb_calib < 20){nb_calib = calib.Ajouter_img_calib(flux.Get_cam());}
		else if(nb_calib == 20){
			calib.Calibrer(flux.Get_cam().size());
			nb_calib++;
		}
		else{
			calib.Set_img(flux.Get_cam());
			gui.Afficher_image("Image calibrée", calib.Get_img());
		}
	}

	return 0;

}
