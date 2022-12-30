#include<stdio.h>
#include<stdbool.h>
#define max(x, y) (((x) > (y)) ? (x) : (y))
#define min(x, y) (((x) < (y)) ? (x) : (y))

int main(){
    int ax, ay, bx, by, cx, cy, dx, dy;
    scanf("%d %d %d %d %d %d %d %d", &ax, &ay, &bx, &by, &cx, &cy, &dx, &dy);

    int abc = (by-ay) * (cx-bx) - (bx-ax) * (cy-by);    
    int abd = (by-ay) * (dx-bx) - (bx-ax) * (dy-by);    
    int cda = (dy-cy) * (ax-dx) - (dx-cx) * (ay-dy);   
    int cdb = (dy-cy) * (bx-dx) - (dx-cx) * (by-dy); 
	  
    abc = (abc == 0) ? 0 : (abc > 0) ? 1 : 2;           
    abd = (abd == 0) ? 0 : (abd > 0) ? 1 : 2;           
    cda = (cda == 0) ? 0 : (cda > 0) ? 1 : 2;           
    cdb = (cdb == 0) ? 0 : (cdb > 0) ? 1 : 2;           

    bool nabrak = false;

    if (abc != abd && cda != cdb) nabrak = true;

    if (abc == 0 && cx <= max(ax,bx) && cx >= min(ax,bx) && cy <= max(ay,by)  && cy >= min(ay,by)) nabrak = true;

    if (abd == 0 && dx <= max(ax,bx) && dx >= min(ax,bx) && dy <= max(ay,by)  && dy >= min(ay,by)) nabrak = true;

    if (cda == 0 && ax <= max(cx,dx) && ax >= min(cx,dx) && ay <= max(cy,dy)  && ay >= min(cy,dy)) nabrak = true;

    if (cdb == 0 && bx <= max(cx,dx) && bx >= min(cx,dx) && by <= max(cy,dy)  && by >= min(cy,dy)) nabrak = true;

    printf(nabrak ? "awas nabrak\n" : "gaspol bangg\n");
    
    return 0;
} 
