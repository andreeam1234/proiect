#include "Park.h"
#include <iostream>
#include "VisitorTooShortException.h"
#include "TicketInvalidException.h"
#include "MaxVisitorsExceededException.h"
#include "Carousel.h"
#include "RollerCoaster.h"
#include "FerrisWheel.h"


int Park::totalVisitors = 0;

/**
 * @brief Constructor for the Park class.
 *
 * Initializes the park with a name and an empty list of attractions and visitors.
 *
 * @param name Name of the park.
 */
Park::Park(const std::string& name) : name(name) {}

/**
 * @brief Copy constructor for the Park class.
 *
 * Creates a copy of another Park object, including all its attractions by cloning them.
 *
 * @param other The park to be copied.
 */
Park::Park(const Park& other) : name(other.name) {
    for (const auto& attraction : other.attractions) {
        attractions.push_back(attraction->clone());
    }
}

/**
 * @brief Copy assignment operator for the Park class.
 *
 * Assigns the contents of another park to the current park.
 *
 * @param other The park to be copied.
 * @return A reference to the current park.
 */
Park& Park::operator=(Park other) {
    swap(*this, other);
    return *this;
}

/**
 * @brief Swap function for the Park class.
 *
 * Swaps the contents of two parks.
 *
 * @param first The first park to swap.
 * @param second The second park to swap.
 */
void swap(Park& first, Park& second) noexcept {
    using std::swap;
    swap(first.name, second.name);
    swap(first.attractions, second.attractions);
}

/**
 * @brief Adds an attraction to the park.
 *
 * @param attraction A shared pointer to the attraction to be added.
 */
void Park::addAttraction(const std::shared_ptr<Attraction>& attraction) {
    attractions.push_back(attraction);
}

/**
 * @brief Retrieves all attractions in the park.
 *
 * @return A const reference to the vector of attractions.
 */
const std::vector<std::shared_ptr<Attraction>>& Park::getAttractions() const {
    return attractions;
}

/**
 * @brief Adds a visitor to the park.
 *
 * @param visitor A shared pointer to the visitor to be added.
 */
void Park::addVisitor(const std::shared_ptr<Visitor>& visitor) {
    visitors.push_back(visitor);
}

/**
 * @brief Displays all attractions in the park.
 *
 * Prints the details of each attraction in the park.
 */
void Park::showAttractions() const {
    std::cout << "Attractions in " << name << ":\n";
    for (const auto& attraction : attractions) {
        std::cout << *attraction << std::endl;
    }
}

/**
 * @brief Displays all visitors in the park.
 *
 * Prints the name and age of each visitor in the park.
 */
void Park::showVisitors() const {
    std::cout << "Visitors in " << name << ":\n";
    for (const auto& visitor : visitors) {
        std::cout << visitor->getName() << " (Age: " << visitor->getAge() << ")\n";
    }
}

/**
 * @brief Simulates the visit of visitors to the attractions.
 *
 * Each visitor attempts to visit each attraction. If an exception occurs (e.g., visitor is too short or max visitors exceeded),
 * it is caught and an error message is displayed.
 */
void Park::visitAttractions() const {
    for (const auto& attraction : attractions) {
        if (auto rollerCoaster = dynamic_cast<RollerCoaster*>(attraction.get())) {
            rollerCoaster->screamTest();
        }
        else if (auto carousel = dynamic_cast<Carousel*>(attraction.get())) {
            carousel->spinAround();
        }
        else if (auto ferrisWheel = dynamic_cast<FerrisWheel*>(attraction.get())) {
            ferrisWheel->enjoyView();
        }
        else {
            attraction->describe();
        }
    }

    // Simulate visitors visiting the attractions
    for (const auto& visitor : visitors) {
        for (const auto& attraction : attractions) {
            try {
                visitor->visitAttraction(attraction);
            } catch (const VisitorTooShortException& e) {
                std::cout << visitor->getName() << " is too short to visit " << attraction->getName() << "\n";
                std::cout << e.what() << std::endl;
            } catch (const MaxVisitorsExceededException& e) {
                std::cout << "Max visitors exceeded for " << attraction->getName() << "\n";
                std::cout << e.what() << std::endl;
            }
        }
    }
}

/**
 * @brief Calculates the total profit from ticket sales.
 *
 * Loops through each visitor and adds the price of their ticket to the total profit.
 * If a visitor has an invalid ticket, a TicketInvalidException is thrown.
 *
 * @return The total profit from ticket sales.
 * @throws TicketInvalidException if a visitor's ticket is invalid.
 */
double Park::calcTotalProfit() const {
    double totalProfit = 0;

    for (const auto& visitor : visitors) {
        if (!visitor->getTicket() || visitor->getTicket()->getPrice() <= 0) {
            throw TicketInvalidException();
        }

        totalProfit += visitor->getTicket()->getPrice();
    }

    return totalProfit;
}

/**
 * @brief Calculates the average time spent by visitors in the park.
 *
 * Sums the time spent by each visitor and divides by the total number of visitors.
 *
 * @return The average time spent by visitors.
 */
double Park::averageTimeSpent() const {
    double totalTime = 0;
    int numberVisitors = 0;
    for (const auto& visitor : visitors) {
        totalTime += visitor->getTimeSpent();
        numberVisitors++;
    }
    return (numberVisitors > 0) ? totalTime / numberVisitors : 0.0;
}

/**
 * @brief Increments the total visitor count for the park.
 */
void Park::incrementTotalVisitors() {
    totalVisitors++;
}

/**
 * @brief Retrieves the total number of visitors for the park.
 *
 * @return The total number of visitors.
 */
int Park::getTotalVisitors() {
    return totalVisitors;
}
