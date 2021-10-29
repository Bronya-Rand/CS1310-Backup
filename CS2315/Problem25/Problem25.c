//--------------------------------------------------
// Dr. Art Hanna
// Problem #25
// Problem25.c
//--------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <math.h>
#include <assert.h>

#include ".\Random.h"

#define SIZEX 100.0
#define SIZEY 100.0

typedef struct POINT
{
   double x;
   double y;
} POINT;

typedef struct SEGMENT
{
   POINT p1;
   POINT p2;
} SEGMENT;

//--------------------------------------------------
int main()
//--------------------------------------------------
{
   void FindConvexHull(const POINT points[],const int n,SEGMENT segments[],int *s);
   void BuildOUTFile(const POINT points[],const int n,const SEGMENT segments[],const int s);

   int n,s;
   POINT *points;
   SEGMENT *segments;

   printf("n? "); scanf("%d",&n);
   points = (POINT *) malloc(sizeof(POINT)*(n+1));
   segments = (SEGMENT *) malloc(sizeof(SEGMENT)*(n+1));
   //printf("points: %d | segments: %d\n\n", points, segments);

   SetRandomSeed();

// choose n random points
   for (int i = 1; i <= n; i++)
   {
      points[i].x = floor((RandomDouble()*SIZEX)*10)/10;
      points[i].y = floor((RandomDouble()*SIZEY)*10)/10;
   }

// find line segments that make up convex hull
   FindConvexHull(points,n,segments,&s);

   assert( s <= n );

// build output file
   BuildOUTFile(points,n,segments,s);

   free(points);
   free(segments);

   system("PAUSE");
   return( 0 );
}

//--------------------------------------------------
void FindConvexHull(const POINT points[],const int n,SEGMENT segments[],int *s)
//--------------------------------------------------
{

	double a = 0.0;
	double b = 0.0;
	double c = 0.0;
	*s = 0;
	for (int i = 1; i <= n-1; i++) {
		for (int j = i + 1; j <= n; j++) {
			a = points[j].y - points[i].y;
			b = points[i].x - points[j].x;
			c = (points[i].x * points[j].y) - (points[i].y * points[j].x);
			int sp = 0;
			int sn = 0;
			for (int k = 1; k <= n; k++) {
				if (k != i && k !=j) {
					if ((a * points[k].x) + (b * points[k].y) - c > 0) {
						sp++;
					}
					else {
						sn++;
					}
				}
			}
			if (sp == 0 || sn == 0) {
				*s = *s + 1;
				segments[*s].p1 = points[i];
				segments[*s].p2 = points[j];
			}
		}
	}

}

//--------------------------------------------------
void BuildOUTFile(const POINT points[],const int n,const SEGMENT segments[],const int s)
//--------------------------------------------------
{
   FILE *OUT;

   OUT = fopen("Problem25.out","w");
   fprintf(OUT,"%5.1f %5.1f\n",SIZEX,SIZEY);
   fprintf(OUT,"%4d\n",n);
   for (int i = 1; i <= n; i++)
       fprintf(OUT,"%5.1f %5.1f\n",points[i].x,points[i].y);
   fprintf(OUT,"%4d\n",s);
   for (int i = 1; i <= s; i++)
   {
      fprintf(OUT,"%5.1f %5.1f  ",segments[i].p1.x,segments[i].p1.y);
      fprintf(OUT,"%5.1f %5.1f\n",segments[i].p2.x,segments[i].p2.y);
   }
   fclose(OUT);
}
