/*
 * @(#)		Carte.h
 * @version	1.0
 * @autor	C. Rouvière
 */

/**
 * Classe contenant une carte de vignettes
 */

#ifndef CARTE
#define CARTE

#include <opencv2/opencv.hpp>
#include "struct_vignette.h"

class Carte{

public:

	Carte();

	void Remplir_buffer(cv::Mat image, std::vector <cv::Point2f> quadrillage);
	void Traiter_buffer();
	void Clear();

private:

	STRUCT_VIGNETTE root;
	bool is_empty;
	std::vector <STRUCT_VIGNETTE> liste;
	std::vector <cv::Mat> buffer_img;
	std::vector <std::vector <cv::Point2f> > buffer_quad;

};

#endif
