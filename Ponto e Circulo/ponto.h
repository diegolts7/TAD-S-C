
typedef struct Ponto{
    float x,y;
}ponto;

ponto *CriarPonto(float x, float y);
void LiberaPonto(ponto *p);
void Acessa(ponto *p, float *x, float *y);
void Atribui (ponto* p, float x, float y);
float distancia (ponto* p1, ponto* p2);