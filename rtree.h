#ifndef RTREE_H_INCLUDED
#define RTREE_H_INCLUDED
#define BUCKET 3

using namespace std;

struct point2d{
    float x,y;
};

struct rectangulo{
    point2d v1,v2;
};

class Nodo{
public:
    rectangulo region;
    rectangulo regs[BUCKET];
    Nodo* hijos[BUCKET];
    int ir,ih;
    Nodo(){
        for(int i=0;i<BUCKET;++i)
            hijos[i]=0;
        ir=0;
        ih=0;
    };
};


class RTree{
    int getArea(rectangulo,rectangulo);
    Nodo* escogerHoja(Nodo*,rectangulo);
    void ajustarArbol();
    void escogerSemillas(Nodo*,rectangulo*,rectangulo*);
    bool escogerSiguiente(rectangulo,rectangulo,rectangulo);
    void dividirNodo();
public:
    Nodo* raiz;
    void insertar(rectangulo);
    void buscar();
};
#endif // RTREE_H_INCLUDED
