typedef struct p *punto;

punto creaPunto(float x, float y);

float ascissa(punto p);

float ordinata(punto p);

float distanza(punto p1, punto p2);

void stampa(punto p);

int eq(punto p1, punto p2);

punto input_punto();