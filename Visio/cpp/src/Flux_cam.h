/*
 * @(#)		Flux_cam.h
 * @version	1.4
 * @autor	C. Rouvière
 */

/**
 * Classe permettant d'exploiter un périphérique vidéo
 *	- contient les deux images précédentes enregistrées
 *	- se met à jour via la procédure "void Update()"
 *	- peut appliquer un changement d'espace de couleur (voir OpenCV doc)
 *	- peut appliquer un lissage pour les webcams de mauvaise qualité
 */

#ifndef FLUX_CAM
#define FLUX_CAM

#include <opencv2/opencv.hpp>

class Flux_cam{

public:

	Flux_cam(
		const int num_device =		-1,	// /dev/video[X] (-2 : réseau, -1 : auto)
		const int delais =			40,	// delais entre deux images
		const int code_couleur =	-1,	// changement espace couleurs
		const int lissage =			-1,	// flou de force lissage
		const int flip =			0,	// miroir (0 : aucun | 1 : selon x | 2 : selon y | 3 : selon x et y)
		const char* adresse =		""	// URL d'un flux réseau
	);

	void Update();			// mettre à jour les images
	char Get_key() const;		// getter sur la clé
	cv::Mat Get_cam() const;	// getter sur image webcam
	cv::Mat Get_prev() const;	// getter sur image N-1
	cv::Mat Get_next() const;	// getter sur image N

private:

	char key;			// clé de contrôle d'exécution
	int code_couleur;		// changement espace couleurs
	int delais;			// temps d'attente entre deux images (en millisecondes)
	int lissage;			// force du flou de lissage
	int flip;			// miroir
	cv::Size flou_kern;		// flou de force lissage
	cv::VideoCapture capture;	// périphérique de capture d'images
	cv::Mat img_cam;		// image webcam
	cv::Mat img_prev;		// image N-1
	cv::Mat img_next;		// image N
	cv::Mat img_show;		// image à afficher

	void Init(const int num_device, const int delais);
	void Init(const int num_device, const int delais, const int code_couleur, const int lissage, const int flip);
	void Attendre(const int millis);
	void Sauvegarder();
	void Recuperer();

};

#endif
