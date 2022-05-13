
#include <iostream>
// goertzel_c_project_demo.cpp : Defines the entry point for the console application.
// 
// This project by itay & nadav is simulation of goertzel method 
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <Mmsystem.h>
#define ALIAS "random_str"
#define _USE_MATH_DEFINES
#include <math.h>
short* BuildSinWave(float Freq, float SamplingFreq, int numOfValue, float Amp);
float goertzel_mag(int numSamples, int TARGET_FREQUENCY, int SAMPLING_RATE);
short* data_in;
int main(int argc, char* argv[])
{
	data_in = BuildSinWave(1200, 2000, 8000, 1024.0);
	//short *data_in2 = BuildSinWave(500.0, 8000.0, 8000, 1024.0);
	//data_in = BuildSinWave(1200.0, 8000.0, 8000, 1024.0);
	//short *data_in2 = BuildSinWave(500.0, 8000.0, 8000, 1024.0);
	//for (int i = 0; i < 8000; i++)
	 // data_in[i] = data_in[i] + data_in2[i];
	//data_in = BuildSinWave(2.0, 100, 200, 1024.0);
	for (int i = 100; i < 2000; i += 10)
	{
		//int mag = (int)(goertzel_mag(205, i, 8000));
		int mag = (int)(goertzel_mag(205, i, 2000));
		printf("freq=%d mag=%d\n", i, mag);
	}
	data_in = BuildSinWave(100.0, 8000.0, 8000, 1024.0);
	//data_in = BuildSinWave(2.0, 100, 200, 1024.0);
	for (int i = 50; i < 200; i++)
	{
		int mag = (int)(goertzel_mag(300, i, 8000));
		printf("freq=%d mag=%d\n", i, mag);
	}
	int y100 = (int)(goertzel_mag(205, 100, 8000)); //1000hz
	int y1000 = (int)(goertzel_mag(205, 1000, 8000)); //1000hz
	return 0;
}
// this function build a sampled sin 
// Freq- The Sin frequncy in Hertz to be created 
// SamplingFreq -The sample rate of this sin signal 
// numOfValue
// Amp
// the purpose is to simpulate how sampled sin loooks like 
// and test later goertzel algorithm on this signal 

short* BuildSinWave(float Freq, float SamplingFreq, int numOfValue, float Amp)
{
	short* p2Signal = (short*)malloc(numOfValue * sizeof(short));
	float Ts = 1.0 / SamplingFreq;
	for (int i = 0; i < numOfValue; i++)
	{
		float rad = 2 * M_PI * Freq * i * Ts;
		float sin_amp = sin(rad);
		p2Signal[i] = (short)Amp * sin_amp + (short)Amp;
	}
	return p2Signal;
}
float goertzel_mag(int numSamples, int TARGET_FREQUENCY, int SAMPLING_RATE)
{
	int k, i;
	float analog;
	float floatnumSamples;
	float omega, sine, cosine, coeff, q0, q1, q2, magnitude, real, imag;
	float scalingFactor = numSamples / 2.0;
	floatnumSamples = (float)numSamples;
	k = (int)(0.5 + ((floatnumSamples * TARGET_FREQUENCY) / SAMPLING_RATE));
	omega = (2.0 * 3.14 * k) / floatnumSamples;
	sine = sin(omega);
	cosine = cos(omega);
	coeff = 2.0 * cosine;
	q0 = 0;
	q1 = 0;
	q2 = 0;
	for (i = 0; i < numSamples; i++)
	{
		analog = data_in[i];
		q0 = coeff * q1 - q2 + analog;
		q2 = q1;
		q1 = q0;
	}
	// calculate the real and imaginary results
	// scaling appropriately
	real = (q1 - q2 * cosine) / scalingFactor;
	imag = (q2 * sine) / scalingFactor;
	magnitude = sqrt(real * real + imag * imag);
	return magnitude;
}
