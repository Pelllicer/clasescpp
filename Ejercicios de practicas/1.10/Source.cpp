/*****************************************************************
FICHERO: circulos.c
AUTOR: JPD
FECHA: 21/2/2016
DESCRIPCION: comprobación de si dos circunferencias en el plano colisionan entre ellas o no
*****************************************************************/

#include <stdio.h>
#include <math.h>

typedef struct //estructura para el circulo
{
	float x;
	float y;
	float r;
} punto;

void PedirDatos(punto* pt1, punto* pt2) //funcion peticion de datos. paso por referencia. (tal como ej.p135)
{
	float coordx1, coordy1, rad1;
	float coordx2, coordy2, rad2;
	printf("Introduzca coordenadas y radio del primer punto.Ej: (#x #y #r)\n");
	scanf("%f %f %f", &coordx1, &coordy1, &rad1);	//en teoria podria valer scanf("%f %f %f", &pt1->x, &pt1->y, &pt1->r);
	printf("Introduzca coordenadas y radio del segundo punto.Ej: (#x #y #r)\n");
	scanf("%f %f %f", &coordx2, &coordy2, &rad2);
	pt1->x = coordx1;
	pt1->y = coordy1;
	pt1->r = rad1;
	pt2->x = coordx2;
	pt2->y = coordy2;
	pt2->r = rad2;
	return;
}

float CalculoDistancia(punto p1, punto p2) //calculo de la distancia entre radios
{
	float delta_x = p1.x - p2.x;
	float delta_y = p1.y - p2.y;
	float abs_x = fabs(delta_x);
	float abs_y = fabs(delta_y);
	float norma = abs_x*abs_x + abs_y*abs_y;
	float dist = sqrt(norma);
	return dist;
}

int ExisteInterseccion(float* p, punto pnt1, punto pnt2)	//funcion booleana comparadora
{
	float d = *p;	//asignacion del puntero *p a la variable local d
	if (d <= (pnt1.r + pnt2.r))	//
		return 1;
	else
		return 0;
}

void main(void)
{
	int booleano;
	punto punto1, punto2;
	PedirDatos(&punto1, &punto2);	//paso por referencia. (tal como ej.p135)
	float d = CalculoDistancia(punto1, punto2);
	booleano = ExisteInterseccion(&d, punto1, punto2);	//llamada a funcion booleana. d pasa por referencia
	if (booleano)
		printf("Existe interseccion\n");
	else
		printf("No existe interseccion\n");
}

