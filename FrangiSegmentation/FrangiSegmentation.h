#pragma once

#include "framework.h"

class CW_Frangi
{
public:
	CW_Frangi();
	~CW_Frangi();

	void SetSigmaStart(const int iSigmaStart) { m_iSigmaStart = iSigmaStart; };
	void SetSigmaEnd(const int iSigmaEnd) { m_iSigmaEnd = iSigmaEnd; };
	void SetSigmaStep(const int iSigmaStep) { m_iSigmaStep = iSigmaStep; };
	void SetBetaOne(const float fBetaOne) { m_fBetaOne = fBetaOne; };
	void SetBetaTwo(const float fBetaTwo) { m_fBetaTwo = fBetaTwo; };
	void SetBlackWhite(const bool bBlackWhite) { m_bBlackWhite = bBlackWhite; };

	cv::Mat Apply(const cv::Mat& mInputImage, const int iSigmaStart = -1,
		const int iSigmaEnd = -1, const int iSigmaStep = -1, const float fBetaOne = -1.0f,
		const float fBetaTwo = -1.0, const bool bBlackWhite = true);

private:

	int m_iSigmaStart;
	int m_iSigmaEnd;
	int m_iSigmaStep;
	float m_fBetaOne;
	float m_fBetaTwo;
	bool m_bBlackWhite; 

};
