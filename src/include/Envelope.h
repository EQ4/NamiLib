/*
* Copyright 2012 Daniel Hjort. All rights reserved.
* Author: Daniel Hjort
*/

#ifndef __ENVELOPE_H__
#define __ENVELOPE_H__

typedef struct {
	double (*func)(double, void*);
	void* data;
} Envelope;

double envelopeY(Envelope* env, double t);

void setEnvelopeFunction(Envelope* env, double (*func)(double, void*), void*);

/*
 *    /\
 *   /  \______
 *  /          \
 *
 *  A - D - S - R
 *
 *  https://en.wikipedia.org/wiki/Synthesizer#ADSR_envelope
 */
typedef struct {
	double attackTime;
	double decayTime;
	double sustainLevel;
	double sustainTime;
	double releaseTime;
} AdsrParamters;

double adsr(double t, void* data);

/*
 * https://en.wikipedia.org/wiki/Raised-cosine_filter
 */
double raisedCosine(double t, void* data);

/*
 * https://en.wikipedia.org/wiki/Gaussian_function
 */
double gaussian(double t, void* data);

#endif
