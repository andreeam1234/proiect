#ifndef VISITOR_LIST_H
#define VISITOR_LIST_H

#include <vector>
#include <memory>
#include "ChildVisitor.h"
#include "AdultVisitor.h"

// Template class to manage a list of visitors
template<typename T>
class VisitorList {
private:
    std::vector<std::shared_ptr<T>> visitors; /**< List of visitors. */

public:
    /**
     * @brief Adds a visitor to the list.
     *
     * @param visitor A shared pointer to the visitor.
     */
    void addVisitor(const std::shared_ptr<T>& visitor) {
        visitors.push_back(visitor);
    }

    /**
     * @brief Displays the information of all visitors in the list.
     */
    void displayVisitors() const {
        for (const auto& visitor : visitors) {
            visitor->displayVisitor();
        }
    }

    /**
     * @brief Finds a visitor by name.
     *
     * @param name The name of the visitor to find.
     * @return A shared pointer to the found visitor, or nullptr if not found.
     */
    std::shared_ptr<T> findVisitorByName(const std::string& name) const {
        for (const auto& visitor : visitors) {
            if (visitor->getName() == name) {
                return visitor;
            }
        }
        return nullptr;
    }

    /**
     * @brief Gets the list of visitors.
     * @return A constant reference to the list of visitors.
     */
    const std::vector<std::shared_ptr<T>>& getVisitors() const {
        return visitors;
    }

    /**
     * @brief Gets the list of visitors (non-const version).
     * @return A reference to the list of visitors.
     */
    std::vector<std::shared_ptr<T>>& getVisitors() {
        return visitors;
    }
};

#endif // VISITOR_LIST_H
