typedef int TipoItem;

struct No {
    TipoItem valor;
    No* proximo;
};

class FilaDinamica {

    private:
    No* primeiro;
    No* ultimo;

    public:
    FilaDinamica();
    ~FilaDinamica();
    bool estaVazia();
    bool estaCheia();
    void inserir(TipoItem item);
    TipoItem remover();
    void imprimir();
};