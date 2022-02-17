#include "FileText.h"

string FileText::pobierzNazwePliku()
{
    return NAZWA_PLIKU;
}

bool FileText::czyPlikJestPusty()
{
    bool pusty = true;
    fstream FileText;
    FileText.open(pobierzNazwePliku().c_str(), ios::app);

    if (FileText.good() == true)
    {
        FileText.seekg(0, ios::end);
        if (FileText.tellg() != 0)
            pusty = false;
    }

    FileText.close();
    return pusty;
}
