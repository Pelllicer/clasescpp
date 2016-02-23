/*****************************************************************
FICHERO: segmento-circulo.c
AUTOR: JPD
FECHA: 21/2/2016
DESCRIPCION: calcular si hay colisión entre un segmento, definido por sus puntos extremos y una circunferencia:
*****************************************************************/

#include <stdio.h>
#include <math.h>

typedef struct			//estructura para el circulo
{
	float x;
	float y;
	float r;
} punto;

typedef struct			//estructura para la linea
{
	float x1;
	float y1;
	float x2;
	float y2;
} linea;

void PedirDatos(punto* pt1, linea* l1)			//funcion peticion de datos. paso por referencia. (tal como ej.p135)
{
	float coordx1, coordy1, rad1;
	float coordx2, coordy2, coordx3, coordy3;
	printf("Introduzca coordenadas y radio del circulo.Ej: (#x #y #r)\n");
	scanf("%f %f %f", &coordx1, &coordy1, &rad1);			//en teoria podria valer scanf("%f %f %f", &pt1->x, &pt1->y, &pt1->r);
	printf("Introduzca primer punto del segmento: (#x #y)\n");
	scanf("%f %f", &coordx2, &coordy2);
	printf("Introduzca segundo punto del segmento: (#x #y)\n");
	scanf("%f %f", &coordx3, &coordy3);
	pt1->x = coordx1;
	pt1->y = coordy1;
	pt1->r = rad1;
	l1->x1 = coordx2;
	l1->y1 = coordy2;
	l1->x2 = coordx3;
	l1->y2 = coordy3;
	return;
}

float CalculoDistancia(punto p1, linea l1)			//calculo de la distancia minima del segmento al centro del circulo
{
	float distanciaLinea,distanciaSegmento;
	float r_numerador = (p1.x-l1.x1)*(l1.x2-l1.x1) + (p1.y-l1.y1)*(l1.y2-l1.y1);
	float r_denominador = (l1.x2-l1.x1)*(l1.x2-l1.x1) + (l1.y2-l1.y1)*(l1.y2-l1.y1);
	float r = r_numerador / r_denominador;
	float px = l1.x1 + r*(l1.x2-l1.x1);
	float py = l1.y1 + r*(l1.y2-l1.y1);
	float s =  ((l1.y1-p1.y)*(l1.x2-l1.x1)-(l1.x1-p1.x)*(l1.y2-l1.y1) ) / r_denominador;
	distanciaLinea = fabs(s)*sqrt(r_denominador);
	float xx = px;
	float yy = py;
	if ( (r >= 0) && (r <= 1) )
	{
		distanciaSegmento = distanciaLinea;
	}
	else
	{
		float dist1 = (p1.x-l1.x1)*(p1.x-l1.x1) + (p1.y-l1.y1)*(p1.y-l1.y1);
		float dist2 = (p1.x-l1.x2)*(p1.x-l1.x2) + (p1.y-l1.y2)*(p1.y-l1.y2);
		if (dist1 < dist2)
		{
			xx = l1.x1;
			yy = l1.y1;
			distanciaSegmento = sqrt(dist1);
		}
		else
		{
			xx = l1.x2;
			yy = l1.y2;
			distanciaSegmento = sqrt(dist2);
		}
	}
	return distanciaSegmento;
}

int ExisteInterseccion(float* p, punto pnt1)			//funcion booleana comparadora
{
	float d = *p;			//asignacion del puntero *p a la variable local d
	if (d <= pnt1.r)			//si la distancia minima es menor que el radio, hay colision
		return 1;
	else
		return 0;
}

void main(void)
{
	int booleano;
	punto punto1;
	linea linea1;
	PedirDatos(&punto1, &linea1);			//paso por referencia. (tal como ej.p135)
	float d = CalculoDistancia(punto1, linea1);			//almacena dist min segmento centro del circulo
	booleano = ExisteInterseccion(&d, punto1);			//llamada a funcion booleana. d pasa por referencia
	if (booleano)
		printf("Existe interseccion\n");
	else
		printf("No existe interseccion\n");
	printf("La distancia minima del centro del circulo al segmento es: %g\n",d);			//calculo pedido de la distancia de un punto a un vector
}
