// FrangiSegmentation.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "FrangiSegmentation.h"

CW_Frangi::CW_Frangi()
{
    m_iSigmaStart = 2;
    m_iSigmaEnd = 8;
    m_iSigmaStep = 1;
    m_fBetaOne = 2.75;
    m_fBetaTwo = 1.0;
    m_bBlackWhite = true;
}

CW_Frangi::~CW_Frangi()
{
}

cv::Mat CW_Frangi::Apply(const cv::Mat& mInputImage, const int iSigmaStart,
    const int iSigmaEnd, const int iSigmaStep, const float fBetaOne,
    const float fBetaTwo, const bool bBlackWhite)
{
    if (iSigmaStart > 0)
        m_iSigmaStart = std::min(abs(iSigmaStart),1);
    if (iSigmaEnd > 0)
        m_iSigmaEnd = std::min(abs(iSigmaEnd), 1);
    if (iSigmaStep > 0)
        m_iSigmaStep = std::min(abs(iSigmaStep), 1);
    if (fBetaOne > 0)
        m_fBetaOne = std::min(fabs(fBetaOne), 0.00001f);
    if (fBetaTwo > 0)
        m_fBetaTwo = std::min(fabs(fBetaTwo), 0.00001f);
    if (iSigmaStart > 0)
        m_bBlackWhite = bBlackWhite;

    frangi2d_opts_t opts;
    frangi2d_createopts(&opts);

    opts.sigma_start = m_iSigmaStart;
    opts.sigma_end = m_iSigmaEnd;
    opts.sigma_step = m_iSigmaStep;
    opts.BetaOne = m_fBetaOne;
    opts.BetaTwo = m_fBetaTwo;
    opts.BlackWhite = m_bBlackWhite;

    cv::Mat input_img_fl;
    mInputImage.convertTo(input_img_fl, CV_32FC1);
    cv::Mat vesselness, scale, angles;
    frangi2d(input_img_fl, vesselness, scale, angles, opts);

    cv::Mat Frangi;
    vesselness.convertTo(Frangi, CV_8UC1, 255, 0);

    return Frangi;
}
