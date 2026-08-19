#pragma once
#include <string>

enum class PurchaseResult { DISPENSED, INSUFFICIENT_PAYMENT, SOLD_OUT, NO_PRODUCT_SELECTED, CANCELLED };

inline std::string resultToString(PurchaseResult r) {
    switch (r) {
    case PurchaseResult::DISPENSED: return "DISPENSED";
    case PurchaseResult::INSUFFICIENT_PAYMENT: return "INSUFFICIENT_PAYMENT";
    case PurchaseResult::SOLD_OUT: return "SOLD_OUT";
    case PurchaseResult::NO_PRODUCT_SELECTED: return "NO_PRODUCT_SELECTED";
    case PurchaseResult::CANCELLED: return "CANCELLED";
    }
    return "UNKNOWN";
}