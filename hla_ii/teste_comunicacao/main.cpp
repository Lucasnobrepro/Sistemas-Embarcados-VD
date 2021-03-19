#include <string>
#include <cstdio>
#include "VirtualBusFederate.h"
/*
#include "svdpi.h"

extern "C" void shift_array;
extern "C" void do_sum(int, int, int);
*/

#define VIRTUALBUS_SIZE 1
#define IMAGE_WIDTH 4
#define IMAGE_HEIGHT 4

#define WINDOW_WIDTH 3
#define WINDOW_HEIGHT 36
//Use to HLA
unsigned int  size;
//string size;
unsigned int data[VIRTUALBUS_SIZE];
//unsigned char* data[VIRTUALBUS_SIZE];

int main( int argc, char **argv ){
  	//****************************************************
	//*********************** HLA ************************
	//****************************************************
	char federateName[20];
	// check to see if we have a federate name
	//strcpy(federateName, "FPGAFederate");
	sprintf(federateName, "%d", FPGA_ID);
	//sprintf(federateName, "%s", FPGA_ID);
	//	if( argc > 1 )
	//		strcpy(federateName,argv[1]);

	// create and run the federate
	VirtualBusFederate *federate;
	federate = new VirtualBusFederate();
	federate->runFederate( federateName );

	//Data to receive
	unsigned src=1;
	//string src=1;
	unsigned addr = 1;
	//string addr = 1;
	int a[IMAGE_HEIGHT][IMAGE_WIDTH];

	while(1){
	  	if(federate->readData(src,addr,size, data)){
			for (size_t i = 0; i < VIRTUALBUS_SIZE; i++) {
				printf(">> %d ", data[i]);
			}
		    	printf("\n");
			//send data by HLA
			addr = SENDER_ID; //Sender address
			a[0][0] = data[0];
			a[0][1] = data[1] ;
			a[0][2] = data[2] ;
			a[0][3] = data[3] ;
			a[1][0] = data[4] ;
			a[1][1] = data[5] ;
			a[1][2] = data[6] ;
			a[1][3] = data[7] ;
			a[2][0] = data[8] ;
			a[2][1] = data[9] ;
			a[2][2] = data[10];
			a[2][3] = data[11];
			a[3][0] = data[12];
			a[3][1] = data[13];
			a[3][2] = data[14];
			a[3][3] = data[15];
			//First compute the first horizontal line
			for(int j = 1; j < IMAGE_WIDTH; j++)
				a[0][j] += a[0][j-1];

			//Then compute the first vertical line
			for(int i = 1; i < IMAGE_HEIGHT; i++)
				a[i][0] += a[i-1][0];

			//And finally compute the rest of the values
			for(int i = 1; i < IMAGE_HEIGHT; i++)
				for(int j = 1; j < IMAGE_WIDTH; j++)
			  		a[i][j] += a[i-1][j]+a[i][j-1]-a[i-1][j-1];


			data[0]  = a[0][0];
			data[1]  = a[0][1];
			data[2]  = a[0][2];
			data[3]  = a[0][3];
			data[4]  = a[1][0];
			data[5]  = a[1][1];
			data[6]  = a[1][2];
			data[7]  = a[1][3];
			data[8]  = a[2][0];
			data[9]  = a[2][1];
			data[10] = a[2][2];
			data[11] = a[2][3];
			data[12] = a[3][0];
			data[13] = a[3][1];
			data[14] = a[3][2];
			data[15] = a[3][3];
		      federate->writeData(src, addr, size,  data);

		}
		else{}

		federate->advanceTime(1.0);
	}

}
