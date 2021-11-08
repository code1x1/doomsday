#include <iostream>
#include <vector>
#include "util.h"

enum DAYS {
    SUNDAY,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
};

uint32_t calculateCentury(uint32_t year);
DAYS calculateCenturyAnchorDay(uint32_t century);
DAYS calculateAnchorDay(uint32_t year);
const char* returnDayName(DAYS d);

uint32_t calculateCentury(uint32_t year) {
    uint32_t century = (year - (year % 100)) / 100;
    return century;
}

DAYS calculateCenturyAnchorDay(uint32_t century) {
    DAYS d;
    bool isNegative = century < 0;
    switch (abs(century) % 4) {
        case 0:
            d = DAYS::TUESDAY;
            break;
        case 1:
            d = isNegative ? DAYS::WEDNESDAY : DAYS::SUNDAY;
            break;
        case 2:
            d = DAYS::FRIDAY;
            break;
        case 3:
            d = isNegative ? DAYS::SUNDAY : DAYS::WEDNESDAY;
            break;
    }
    return d;
}

DAYS calculateDoomsDay(uint32_t year) {
    uint32_t T = year % 100;
    if (isOdd(T)) T += 11;
    T /= 2;
    if (isOdd(T)) T += 11;
    T = 7 - (T % 7);
    uint32_t century = calculateCentury(year);
    DAYS centuryAnchorDay = calculateCenturyAnchorDay(century);
    return (DAYS)((T + centuryAnchorDay) % 7);
}

const char* returnDayName(DAYS d) {
    switch (d) {
    case DAYS::MONDAY:
        return "MONDAY";
        break;
    case DAYS::TUESDAY:
        return "TUESDAY";
        break;
    case DAYS::WEDNESDAY:
        return "WEDNESDAY";
        break;
    case DAYS::THURSDAY:
        return "THURSDAY";
        break;
    case DAYS::FRIDAY:
        return "FRIDAY";
        break;
    case DAYS::SATURDAY:
        return "SATURDAY";
        break;
    default:
        return "SUNDAY";
    }
}

int main(int argc, char const *argv[]) {
    std::cout << "doomsday algorithm :)" << std::endl;
    for (int i = 2021; i < 2023; i++) {
        std::cout << "doomsday " << i << " " << returnDayName(calculateDoomsDay(i)) << std::endl;
    }
    return 0;
}
