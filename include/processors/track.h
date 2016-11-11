#ifndef PRISM_CONNECT_PROCESSORS_Track_H_
#define PRISM_CONNECT_PROCESSORS_Track_H_

#include <chrono>

#include <json.hpp>

namespace prism {
namespace connect {
namespace processors {

typedef struct {
    int x;
    int y;
    int td_milliseconds;
} TrackPoint;

class Track {
  public:
    Track(int id, const std::chrono::system_clock::time_point& start_time);

    void AddPoint(const int x, const int y, const std::chrono::system_clock::time_point& timestamp);
    void AddPoint(const int x, const int y, const int time_difference);

    nlohmann::json ToJson() const;

  private:
    nlohmann::json data_;
    std::chrono::system_clock::time_point last_time_;
};

/*
 * [
 *   {
 *     "id": int,
 *     "timestamp": "ISO",
 *     "points": [
 *        [x, y, td],
 *        [x, y, td],
 *     ]
 *   },
 *   {
 *     "id": int,
 *     "timestamp": "ISO",
 *     "points": [
 *        [x, y, td],
 *        [x, y, td],
 *     ]
 *   }
 * ]
 */

} // namespace processors
} // namespace connect
} // namespace prism

#endif // PRISM_CONNECT_PROCESSORS_Track_H_
