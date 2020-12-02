/*
 * Uma estufa de flores é monitorada por 25 sensores que registram a temperatura e umidade.  
 * Estes sensores enviam a temperatura e o grau de umidade em determinados horários. 
 * Faça um programa, utilizando a função abaixo, que leia os registros de cada sensor 
 * (o horário (h e m), a temperatura e o grau de umidade - 
 * término dos registros de um sensor: hora = = -1) e apresente, para cada sensor: 
 * (1) a menor  temperatura  e em que horário ocorreu 
 * (2) o menor  grau de umidade e em que horário ocorreu
 * 
 * No final  o programa deve mostrar qual sensor registrou a menor temperatura e qual sensor 
 * registrou o menor grau de umidade 
 * 
 * a) Faça a função um_sensor que receba como parâmetros o endereço de duas variáveis reais. 
 * Esta função deverá ler os dados de um sensor, exibir  a menor  temperatura  e em que horário 
 * ocorreu, o menor  grau de umidade e em que horário ocorreu e armazenar, nas variáveis cujos 
 * endereços são fornecidos, a menor temperatura e o menor grau de umidade registrados por ele.
 * Protótipo da função: void um_sensor (float *menortemp, float *menorumidade);
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SENSOR 25

void aSensor(float *lowTemp, float *lowHumid);

int main(void){
	float lowTemp, lowHumid, minTemp, minHu;
	int count=1, lowTempSensor, lowHumidSensor;
	// srand was used in order to generate random inputs in to sensors
	srand(time(NULL)); 
   
	lowTemp = lowHumid = minTemp = minHu = -1;
	
	while(count <= SENSOR){
		printf("\n**** Sensor %i ****\n", count);
		aSensor(&lowTemp, &lowHumid);
		if(minTemp == -1){
			minTemp = lowTemp;
			lowTempSensor = count;
		}else{
			if(lowTemp < minTemp){
				minTemp = lowTemp;
				lowTempSensor = count;
			}
		}
		if(minHu == -1){
			minHu = lowHumid;
			lowHumidSensor = count;
		}else{
			if(lowHumid < minHu){
				minHu = lowHumid;
				lowHumidSensor = count;
			}
		}
				
		count++;
		lowTemp = lowHumid = -1;
	}
	
	printf("\n**************************************************\n");
	printf("Sensor with lowest temperature markup.. %2i .... %2.1f°C\n", lowTempSensor,minTemp);
	printf("Sensor with lowest humidity markup..... %2i .... %2.1f%%\n", lowHumidSensor, minHu);
	
	return 0;
}

void aSensor(float *lowTemp, float *lowHumid){
	int hour, minute, hourRefTemp, minuteRefTemp, hourRefHu, minuteRefHu;
	float temp, humidity;
	int ref;
	
	hour = rand() % 25;
	while(hour != -1){
		minute = rand() % 61;
		/* many rands was used in temp and humidity variables in order to get different of zero 
		 * or very low values */
		temp = (rand()%31) + (rand()%37) + (rand()%41);
		humidity = (rand()%31) + (rand()%37) + (rand()%71);
		if(humidity > 100){
			humidity = 100;
		}
		if((*lowTemp) == -1){
			(*lowTemp) = temp;
			hourRefTemp = hour;
			minuteRefTemp = minute;
		}else{
			if(temp < (*lowTemp)){
				(*lowTemp)=temp;
				hourRefTemp = hour;
				minuteRefTemp = minute;
			}
		}
		if((*lowHumid) == -1){
			(*lowHumid) = humidity;
			hourRefHu = hour;
			minuteRefHu = minute;
		}else{
			if(humidity < (*lowHumid)){
				(*lowHumid)=humidity;
				hourRefHu = hour;
				minuteRefHu = minute;
			}
		}
		
		hour = rand() % 25;
		ref = rand() % 25;
		hour = ref - hour;
		if(hour < 0){
			hour = -1;
		}
	}
	
	printf("Lowest temperature: %2.1f at %ih %imin\n", (*lowTemp), hourRefTemp, minuteRefTemp);
	printf("Lowest humidity: %2.1f at %ih %imin\n", (*lowHumid), hourRefHu, minuteRefHu);
	
	return;
}
