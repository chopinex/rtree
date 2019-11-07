#include "rtree.h"
#include <math.h>
#include<algorithm>

using namespace std;

int RTree::getArea(rectangulo r1,rectangulo r2){
    int x,y;
    if(r2.v1.x<r1.v1.x)
        x=r1.v2.x-r2.v1.x;
    else{
        if(r2.v2.x>r1.v2.x)
            x=r2.v2.x-r1.v1.x;
        else
            x=r1.v2.x-r1.v1.x;
    }
    if(r2.v1.y>r1.v1.y)
        y=r2.v1.y-r1.v2.y;
    else{
        if(r2.v2.y<r1.v2.y)
            y=r1.v1.y-r2.v2.y;
        else
            y=r1.v1.y-r1.v2.y;
    }
    return x*y;
}

Nodo* RTree::escogerHoja(Nodo* n,rectangulo r){
     if(!n||!n->ih)
        return n;
    int minarea=1<<30,actarea,actindex=0;
    for(int i=0;i<n->ih;++i){
        actarea=getArea(n->hijos[i]->region,r);
        if(actarea<minarea){
            minarea=actarea;
            actindex=i;
        }
    }
    return escogerHoja(n->hijos[actindex],r);
}
void RTree::escogerSemillas(Nodo* n,rectangulo* e1,rectangulo* e2){
    float d1,d2,dd,dmax=0;
    rectangulo* ee1;
    rectangulo* ee2;
    for(int i=0;i<BUCKET-1;++i){
        ee1=&(n->regs[i]);
        for(int j=1;j<BUCKET;++j){
            ee2=&(n->regs[j]);
            d1=fabs(e1->v1.x-e2->v2.x);
            d2=fabs(e2->v1.x-e1->v2.x);
            dd=max(d1,d2);
            if(dd>dmax){
                e1=ee1;
                e2=ee2;
            }
        }
    }
}

bool RTree::escogerSiguiente(Nodo* n,rectangulo s1,rectangulo s2){
    int a1=getArea(n->regs[i],s1);
    int a2=getArea(n->regs[i],s2);
    return(a1<a2);
}

void RTree::insertar(rectangulo r){
    Nodo* n=escogerHoja(raiz,r);
    if(n->ir<BUCKET-1){
        n->regs[n->ir]=r;
        n->ir++;
    }
    else{
        rectangulo* e1=0;
        rectangulo* e2=0;
        escogerSemillas(n,e1,e2);
        rectangulo g1[BUCKET/2+1];
        rectangulo g2[BUCKET/2+1];
        for(int i=0;i<n->ir;++i){

        }
    }
}
