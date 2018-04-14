void constroi_solucao(int n, int *s, float **distancia);

/* Constroi uma solucao de forma gulosa usando o método do vizinho mais proximo */
void constroi_solucao_gulosa_vizinho_mais_proximo(int n, int *s, float **d);

/* Constroi uma solucao de forma aleatoria */
void constroi_solucao_aleatoria(int n, int *s, float **d);

/* Constroi uma solucao parcialmente gulosa com base no metodo do vizinho mais proximo */
void constroi_solucao_parcialmente_gulosa_vizinho_mais_proximo(int n, int *s, float **d, float alpha);

/* Constroi uma solucao gulosa usando o método da insercao mais barata */
void constroi_solucao_gulosa_insercao_mais_barata(int n, int *s, float **d);

/* Constroi uma solucao parcialmente gulosa com base no metodo da insercao mais barata */
void constroi_solucao_parcialmente_gulosa_insercao_mais_barata(int n, int *s, float **d, float alpha);

