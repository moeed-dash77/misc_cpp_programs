/*
Aufgabe: Online_Shop
Nachname: Abdul Moeed
Vorname: Muhammad
*/

#include <iostream>
#include<iomanip>

using namespace std;

//SUBTASK 1
class Article
{
    private:
        string model;
        double netPrice;
        double taxRate;
    public:
        Article(string c1_model, double c1_netPrice, double tax = 0.19) : model(c1_model), netPrice(c1_netPrice), taxRate(tax){}

        virtual ~Article()
        {
            cout << "~Article() " << model;
        }
        void set_model(string Model)
        {
            model = Model;
        }
        void set_netPrice(double net_Price)
        {
            netPrice = net_Price;
        }
        string get_model()
        {
            return model;
        }
        double get_netPrice()
        {
            return netPrice;
        }
        double get_grossPrice()
        {
            double grossPrice;
            grossPrice = netPrice + (netPrice * taxRate);
            return grossPrice;
        }

        virtual print() = 0;
};

//SUBTASK 2
class Accessory : public Article
{
    private:
        bool original;
    public:
        Accessory(string c2_model, double c2_netPrice, bool c1_original = true ) : Article(c2_model,c2_netPrice), original(c1_original){}
        virtual ~Accessory()
        {
            cout << "~Accessory() ";
        }
        virtual print()
        {
            if (original == true)
            {
                cout << get_model() << " (original accessory)" << endl;
            }
            else
            {
                 cout << get_model() << endl;
            }
        }

};


//SUBTASK 3
enum OperatingSystem{
    unknown,
    android,
    iOS,
    macOS,
    linux,
    proprierty,
    unix,
    windows,
};

ostream& operator<<(ostream& out, OperatingSystem os)
{
    switch(os)
    {
        case 0:
            out << "unknown OS";
            break;
        case 1:
            out << "Android OS";
            break;
        case 2:
            out << "iOS";
            break;
        case 3:
            out << "MacOS";
            break;
        case 4:
            out << "Linux OS";
            break;
        case 5:
            out << "proprietary OS";
            break;
        case 6:
            out << "Unix OS";
            break;
        case 7:
             out << "Unix OS";
             break;
    }
    return out;
}


//SUBTASK 4
class Device : public Article
{
    private:
        int main_memory;
        OperatingSystem os;
    public:
        Device(string c3_model, double c3_netPrice, int c1_memory, OperatingSystem c1_os = unknown) :
            Article(c3_model, c3_netPrice), main_memory(c1_memory), os(c1_os){};
        virtual ~Device()
        {
            cout << "~Device() ";
        }
        OperatingSystem get_os()
        {
            return os;
        }
        virtual print()
        {
            cout << Article::get_model() << ", RAM " << main_memory << "GB, " << os << ", ";
        }

};

//SUBTASK 5
class Notebook : public Device
{
    private:
        string drive;
        bool convertible;
    public:
        Notebook(string c4_model, double c4_netPrice, int c2_memory, OperatingSystem c2_os = linux, string c1_drive = "", bool c1_convertible = false) :
        Device(c4_model, c4_netPrice, c2_memory, c2_os), drive(c1_drive), convertible(c1_convertible){}
        virtual ~Notebook()
        {
            cout << "~Notebook() ";
        }
        bool is_a_convertible()
        {
            if (convertible == true)
                {
                    return true;
                }
            else
            {
                if(convertible == false)
                    {
                            return false;
                    }
            }
        }
        virtual print()
        {
            Device::print();
            if(is_a_convertible())
            {
                cout << " (convertible)" << drive;
            }
            else
            {
                cout << drive << endl;
            }
        }
};


//SUBTASK 6
class Phone : public Device
{
public:
        Phone(string c5_model, double c5_netPrice, int c3_memory = 4, OperatingSystem c3_os = android) :
            Device(c5_model, c5_netPrice, c3_memory, c3_os){}
        virtual ~Phone()
        {
            cout << "~Phone() ";
        }
        virtual print()
        {
            Device::print();
            cout << "phone";
        }
};

//SUBTASK 7
class InCart
{
    private:
        Article *article;
        int amount;
        InCart *next;
    public:
        InCart(Article *c1_article, int Amount = 0, InCart *Next = nullptr) : article(c1_article), amount(Amount), next(Next) {}
        virtual ~InCart()
        {
            cout << "~InCart() " << amount << " ";
            delete article;
            cout << endl;
        }
        InCart* get_next()
        {

            return next;
        }
        virtual print()
        {
            cout << amount << "  " << article->get_model() << endl;
            cout << "      " << article->get_grossPrice() << " EUR" << setw(10) << amount * article->get_grossPrice() << " EUR" << endl;

        }
};


//SUBTASK 8
class ShoppingCart
{
    private:
        InCart *names;
        double minFreeShipping;
        double sumNetPrice;
        double sumGrossPrice;
    public:

        ShoppingCart(InCart *shopping_list = nullptr, double min_FreeShipping = 1000, double sum_NetPrice = 0, double sum_GrossPrice = 0) :
        names(shopping_list), minFreeShipping(min_FreeShipping), sumNetPrice(sum_NetPrice), sumGrossPrice(sum_GrossPrice){}

        ~ShoppingCart()
        {
            cout << "~ShoppingCart() " << endl << "delete article: ";
        }
        void set_minFreeShipping(double min_FreeShipping)
        {
            minFreeShipping = min_FreeShipping;
        }

        void add_article(int shop_amount, Article *article_1)
        {
            InCart *obj_InCart = new InCart(article_1, shop_amount);
            if (names == nullptr)
            {
                    names = obj_InCart;

            }
            else
            {
                    InCart *temp;
                    temp = obj_InCart;
                    //temp->get_next() = names;
                    names =  temp;
                    delete temp;
            }



        }//???

        virtual print()
        {
            if (sumNetPrice >= 500)
            {
                minFreeShipping = 0;
            }

            cout << "========================" << endl << "PROTO-TEC-SHOP" << endl << "YOUR SHOPPING CART" << endl << "========================" << endl;
            InCart *temp1;
            temp1 = names;
            while (temp1 != nullptr)
            {
                 temp1->print();
                 temp1 = temp1->get_next();
            }
           cout << "-------------------------------"<<endl
                << "   sum net price:" << setw(10) << sumNetPrice << " EUR"  << endl
                << "             tax:" << setw(10) << (sumGrossPrice - sumNetPrice) << " EUR" << endl
                << " sum gross price:" << setw(10) << sumGrossPrice << " EUR" << endl
                << "-------------------------------"<<endl
                << "        shipping:" << setw(10) << minFreeShipping << " EUR" << endl
                << "-------------------------------"<<endl
                << "           total:" << setw(10) << minFreeShipping + sumGrossPrice << " EUR" << endl
                << "===============================" << endl << endl;

        }
};


//SUBTASK 9
int main()
{
    ShoppingCart *obj_1 = new ShoppingCart(nullptr, 5.90, 93.24, 110.96);

    //Article *obj_2 = new Article("YOOLOX 10k Wireless Powerbank Qi", 31.08);
    //

    Accessory *obj_3 = new Accessory("YOOLOX 10k Wireless Powerbank Qi", 31.08, false);
    InCart *obj_2 = new InCart(obj_3, 3);
    //obj_2 = obj_3;


    obj_1->add_article(3, obj_3);
    obj_1->print();

    //Phone *obj_4 = new Phone("Samsung Galaxy S10+ SM-G975F/DS Dual SIM", 661.67, 8, android);
    //obj_1->add_article(1, obj_4);
    //Phone *obj_5 = new Phone("Apple iPhone 11 Pro 256GB",  1097.47, 4, iOS);
    //obj_1->add_article(2, obj_5);

    //Notebook *obj_6 = new Notebook("ASUS ROG Strix Scar III G731", 1586.55, 16, window, "512GB SSD + 1TB SSHD");
    //obj_1->add_article(1, obj_6);
    //obj_1->print();





    delete obj_1;
    delete obj_2;
    delete obj_3;
  //delete obj_4;
  //delete obj_5;
  //delete obj_6;

    cout << endl;

}
