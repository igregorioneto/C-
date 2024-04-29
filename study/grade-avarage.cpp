#include <iostream>
#include <string>
#include <vector>
#include <limits>

int main() {
    std::cout << "Digite as notas dos alunos (insira um número negativo para terminar):" << std::endl;
    float note;
    int count = 1;
    std::vector<float> notes;

    while (true)
    {
        std::cout << "Nota " << count << ": ";
        std::cin >> note;
        
        if (std::cin.fail())
        {
            std::cin.clear(); // Limpa o estado de erro
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');// descarta entrada inválida
            std::cout << "Entrada inválida, por favor, insira um número." << std::endl;
            continue;
        }

        if (note < 0)
        {
            break;
        }

        if (note > 100)
        {
            std::cout << "Nota inválida, insira um valor entre 0 e 100." << std::endl;
            continue;
        }

        notes.push_back(note);
        count++;
    }

    // Média das notas: 86.25
    float total = 0;
    float max = 0;
    float min = 100;
    for (float n: notes)
    {
        total += n;
        if (n > max)
        {
            max = n;
        }

        if (n < min)
        {
            min = n;
        }
    }
    std::cout << "Média das notas: " << (total / notes.size()) << std::endl;
    // Nota mais alta: 92
    std::cout << "Nota mais alta: " << max << std::endl;    
    // Nota mais baixa: 78 
    std::cout << "Nota mais baixa: " << min << std::endl;  
    
    return 0;
}