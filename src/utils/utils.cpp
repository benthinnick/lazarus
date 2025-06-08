#include <nlohmann/json.hpp>
// Custom serialization for shared_ptr<T>
template <typename T>
void to_json(nlohmann::json &j, const std::shared_ptr<T> &ptr) {
  if (ptr) {
    j = *ptr; // Dereference shared_ptr to serialize the object it points to
  } else {
    j = nullptr; // Handle the case of null shared_ptr
  }
}

// Custom deserialization for shared_ptr<T>
template <typename T>
void from_json(const nlohmann::json &j, std::shared_ptr<T> &ptr) {
  if (j.is_null()) {
    ptr = nullptr;
  } else {
    ptr = std::make_shared<T>(j.get<T>()); // Deserialize into shared_ptr
  }
}

// Template function for serializing container of shared_ptr
template <typename T, typename Container>
void to_json(nlohmann::json &j, const Container &c) {
  for (const auto &ptr : c) {
    j.push_back(*ptr); // Dereference shared_ptr to serialize the object
  }
}

// Template function for deserializing container of shared_ptr
template <typename T, typename Container>
void from_json(const nlohmann::json &j, Container &c) {
  for (const auto &elem : j) {
    c.push_back(
        std::make_shared<T>(elem.get<T>())); // Deserialize into shared_ptr
  }
}
