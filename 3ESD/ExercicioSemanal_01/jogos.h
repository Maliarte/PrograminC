
typedef struct {
  int idade;
  int genero;
  float notaJogo1;
  float notaJogo2;
  float distancia;
} Candidato;


int sorteio(int Inf, int Sup);
void sorteioCandidatos(Candidato candidatos[], int totalUsuarios);
float calcDist(float x1, float y1, float x2, float y2);
int validaCandidato(float nota1, float nota2);
void bubbleSort(Candidato array[], int tam);
void mostrarCandidatos(Candidato candidatos[], int totalAprovados);
