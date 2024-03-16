#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>


class Produs {
private:
    std::string nume;
    float pret;
    std::string categorie;
    float greutate;

public:
    void set_nume(std::string nume) { this->nume = nume; }
    void set_pret(float pret) { this->pret = pret; }
    void set_categorie(std::string categorie) { this->categorie = categorie; }
    void set_greutate(float greutate) { this->greutate = greutate; }

    std::string get_nume() { return nume; }
    float get_pret() { return pret; }
    std::string get_categorie() { return categorie; }
    float get_greutate() { return greutate; }

    void afisare()
    {
        std::cout << nume << ", " << categorie << ", ";
        std::cout << std::fixed << std::setprecision(1) << pret << " lei, ";
        if (greutate == int(greutate))
        {
            std::cout << std::fixed << std::setprecision(0) << greutate << " kg" << '\n';
        }
        else
        {
            std::cout << std::fixed << std::setprecision(1) << greutate << " kg" << '\n';
        }
    }

    void filtrare(int nrprod, Produs vector[], std::string categorie)
    {
        int x = 0;
        for (int i = 0; i < nrprod; ++i)
        {
            if (vector[i].get_categorie() == categorie)
                vector[i].afisare();
        }
        for (int i = 0; i < nrprod; ++i)
        {
            if (vector[i].get_categorie() != categorie)
            {
                x++;
            }
            if (x == nrprod)
            {
                std::cout << "N/A" << std::endl;
            }
        }

    }

    void unic(int nrprod, Produs vector[], std::string nume)
    {
        for (int i = 0; i < nrprod; ++i)
        {
            vector[i].get_nume();
            int x = 0;
            for (int i = 0; i < nrprod; ++i)
            {
                if (vector[i].get_nume() == nume)
                {
                    x++;
                }
            }
            std::cout << nume << ", " << categorie << ", ";
            std::cout << std::fixed << std::setprecision(1) << pret << " lei, ";
            if (greutate == int(greutate))
            {
                std::cout << std::fixed << std::setprecision(0) << greutate << " kg, ";
            }
            else
            {
                std::cout << std::fixed << std::setprecision(1) << greutate << " kg, ";
            }
            std::cout << x << " buc" << '\n';
        }
    }

   void t_weight(int nrprod, Produs vector[])
    {
        float g = 0;
        for (int i = 0; i < nrprod; ++i)
        {
            g = g + vector[i].get_greutate();
        }
        std::cout << std::fixed << std::setprecision(2) << g;
    }

   void price(int nrprod, Produs vector[], int pg, float cost_aditional)
    {
        float g = 0, x = 0, p = 0, a = 0;
        for (int i = 0; i < nrprod; ++i)
        {
            g = g + vector[i].get_greutate();
        }
        x = g - pg;
        a = ceil(x);
        for (int i = 0; i < nrprod; ++i)
        {
            p = p + vector[i].get_pret();
        }

        std::cout << std::fixed << std::setprecision(1) << p + (a * cost_aditional);
    }

};

int main()
{
    std::string nume;
    float pret;
    std::string categorie, categorie_noua;
    float greutate;
    int nrprod;

    std::cin >> nrprod;

    Produs produse[20];

    for (int i = 0; i < nrprod; ++i)
    {
        std::cin.ignore();
        std::getline(std::cin, nume);
        std::getline(std::cin, categorie);
        std::cin >> pret;
        std::cin >> greutate;

        produse[i].set_nume(nume);
        produse[i].set_categorie(categorie);
        produse[i].set_pret(pret);
        produse[i].set_greutate(greutate);
    }

    int comanda;
    std::cin >> comanda;

    switch (comanda)
    {
    case 1:
        for (int i = 0; i < nrprod; ++i)
        {
            produse[i].afisare();
        }
        break;
    case 2:

        std::cin.ignore();
        std::getline(std::cin, categorie_noua);
        produse[0].filtrare(nrprod, produse, categorie_noua);
        break;
    case 3:

        break;
    case 4:
        produse[0].t_weight(nrprod, produse);
        break;
    case 5:
        int pg;
        float cost_aditional;
        std::cin >> pg >> cost_aditional;
        produse[0].price(nrprod, produse, pg, cost_aditional);
        break;
    }
}