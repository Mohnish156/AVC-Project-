#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include "E101.h"
#include <cmath>
#include <stdlib.h>

int error();

int main(){
	
	//Quad 1: Gate opening
	   int connect = 0;
	   int request = 0;
	   char address[15] = "130.195.6.196";
	   char say[24] = "Please";
	
	   connect = connect_to_server(address, 1024);
	
	   send_to_server(say);
	   request = receive_from_server(say);
	   send_to_server(say);
		
		int err;
		err = init(0);
		
		//Variables
		
		double vleft = 0;
		double vright = 0;
		int leftspeed = 55; 
		int rightspeed = 40;
		double lasterror = 0;
		double currenterror = 0;
		double de = 0;
		double kd = 0.000075;
		double kp = 0.00065;
		double adjust = 0;
		
		//Quad 2: Following Line	
		
	while(true){
			
	
			
			sleep1(100);
			de = (currenterror - lasterror)/0.1;
			adjust = kp * currenterror + kd * de;
			vright = rightspeed + adjust;
			vleft = leftspeed + adjust; 
			
		
			if(vleft>=60){
				printf(vleft); 
				vleft = 60;
				}
			if(vright<=35){
				vright = 35;
				} 
			printf("VLeft = %f Vright = %f\n", vleft, vright);
			set_motors(5, vleft);
			set_motors(3, vright);
			hardware_exchange();
			
			
		}
		
		
	}
	//Gets the error of the line
	int error(){
		
		
		int index[320];
			int lineval[320];
			int startrow = 0;
			int countc = 0;
			double currentblack = 0;
			
			double currentgreen = 0;
			
			
			int indexcount = 0;
			int indexval = 0;
			int position = 0;
			while(indexcount < 320){
				
				indexval = indexcount - 160;
				index[indexcount] = indexval;
				indexcount++;
				
				}
			take_picture();

			
			countc = 0; 
			pos = 0;
			

				while(countc<320){
					
					currentcolour = get_pixel(startrow,countc,1);
					
					currentblack = currentcolour;
					
					if(currentblack>150){
						lineval[countc] = 0;
								
						
					}else{
						lineval[countc] = 1;
						
						}
						countc++;
					}
					
				
				
				for(int i = 0; i<320; i++){
						pos = pos + (index[i]*lineval[i]);
											
					
					}
					
					
				}
					return position;
				}
			
					
					
				
