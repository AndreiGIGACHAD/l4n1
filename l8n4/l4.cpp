#include <iostream>
#include <iomanip>
#include <vector>
#include <numeric>

int main() {
    int num_events;
    std::cout << "������� ���������� �������: ";
    std::cin >> num_events;

    if (num_events <= 0) {
        std::cout << "���������� ������� ������ ���� ������ ����." << std::endl;
        return 1;
    }

    std::vector<double> probabilities(num_events);
    std::cout << "������� ����������� ������� ������� (����������� ���������): ";
    for (int i = 0; i < num_events; ++i) {
        std::cin >> probabilities[i];
        if (probabilities[i] < 0.0 || probabilities[i] > 1.0) {
            std::cout << "����������� ������� ������� ������ ���������� � ��������� [0, 1]." << std::endl;
            return 1;
        }
    }

    double probability = std::accumulate(probabilities.begin(), probabilities.end(), 1.0, std::multiplies<double>());

    std::cout << "����������� ����, ��� ��� ������� ���������� ������: " << std::fixed << std::setprecision(4) << probability << std::endl;

    return 0;
}