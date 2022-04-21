typedef int TipoItem;
const int MAX_ITENS = 100;

class pilha {
    
    private:
    int tamanho;
    TipoItem* estrutura;

    public:
    pilha();  // construtora
    ~pilha(); // destrutora
    bool estaCheia();
    bool estaVazia();
    void inserir(TipoItem item);
    TipoItem remover();
    void imprimir();
    int getTamanho();

};