/*
 * @(#)		Reco.h
 * @version	2.0
 * @autor	C. Rouvière
 */

/**
 * Classe de reconnaissance de formes
 */

#ifndef RECO
#define RECO

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "Utils.h"

class Reco{

public:

	Reco();

	void Set_blobs_1(const std::vector <cv::Point2f> blobs_1);
	void Set_blobs_2(const std::vector <cv::Point2f> blobs_2);
	void Set_size(const cv::Size taille);

	std::vector <bool> Test_circle();
	std::vector <cv::Point2f> Test_inclusion(const int dist_max);

private:

	cv::Scalar blanc;
	cv::Size taille;
	std::vector <cv::Point2f> blobs_1;
	std::vector <cv::Point2f> blobs_2;
	cv::Mat mat_1, mat_2;
	cv::Mat mat_blobs_1, mat_blobs_2;
	cv::Mat mat_compare;
	std::vector <std::vector <cv::Point2i> > liste_blobs;
	std::vector <cv::Vec4i> hierarchie_blobs;
	std::vector <cv::Moments> mu;
	std::vector <cv::Point2f> mc;

	void Update_mats(const int rayon);

};

#endif
