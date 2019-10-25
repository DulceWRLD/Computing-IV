// Copyright Lucas Faletra 2019
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <boost/regex.hpp>
#include "boost/date_time/gregorian/gregorian.hpp"
#include "boost/date_time/posix_time/posix_time.hpp"



using boost::posix_time::time_duration;

int main(int argc, char* argv[]) {
  // input output files
  std::ifstream log(argv[1]);
  std::string out_name = std::string(argv[1]);
  out_name += ".rpt";
  std::ofstream out(out_name.c_str());
  // counters
  int lines_read = 0;
  int boot_successes = 0;
  int boot_total = 0;
  // empty strings used later
  std::string rep, line, boots, start_date, end_date, full_date;
  boost::smatch sm;
  // vector to hold hours minutes seconds
  std::vector<int> hms;
  hms.resize(3);
  // variables for time taken to complete and dates
  boost::posix_time::ptime begin, end;
  boost::gregorian::date d1, d2;
  boost::posix_time::time_duration time_difference;
  bool found_start = false;
  // first string in file probably something like this
  std::string start_string = "([0-9]{4})-([0-9]{2})-([0-9]{2}) ";
  start_string += "([0-9]{2}):([0-9]{2}):([0-9]{2}): \\(log.c.166\\) ";
  start_string += "server started";
  // make a regex for the start string
  boost::regex start_regex(start_string, boost::regex::perl);
  // end string should be something like this
  std::string end_string = "([0-9]{4})-([0-9]{2})-([0-9]{2}) ";
  end_string += "([0-9]{2}):([0-9]{2}):([0-9]{2}).([0-9]{3}):INFO:oejs.";
  end_string += "AbstractConnector:Started SelectChannelConnector@0.0.0.0:9080";
  // make a regex for the last string
  boost::regex end_regex(end_string);

  // read info while log is open, line by line
  if (log.is_open()) {
    while (getline(log, line)) {
      // clear strings for dates each iteration
      start_date.clear();
      end_date.clear();

      // perform operations on start regex
      if (boost::regex_search(line, sm, start_regex)) {
        start_date = sm[1] + "-" + sm[2] + "-" + sm[3];
        end_date += " " + sm[4] + ":" + sm[5] + ":" + sm[6];

        full_date = sm[1] + "-" + sm[2] + "-" + sm[3];
        d1 = boost::gregorian::date
          (boost::gregorian::from_simple_string(full_date));
      // reset hours minutes seconds in vector
        hms[0] = std::stoi(sm[4]);
        hms[1] = std::stoi(sm[5]);
        hms[2] = std::stoi(sm[6]);
       // set begin time
        begin = boost::posix_time::ptime
           (d1, time_duration(hms[0], hms[1], hms[2]));

       // if error found, append incomplete to boot string
        if (found_start == true) {
          boots += "Incomplete boot\n";
        }
       // append the starting boot info to the boot string
        boots += "Device booted\n";
        boots += std::to_string(lines_read) + "(" + out_name + "): ";
        boots += start_date + " Boot Start\n";

       // increment # of boots
        boot_total++;
        found_start = true;
      }
      // check for a match based on regex
       if (boost::regex_match(line, sm, end_regex)) {
       // if match, append the elements of the smatch variable
        end_date = sm[1] + "-" + sm[2] + "-" + sm[3];
        end_date += " " + sm[4] + ":" + sm[5] + ":" + sm[6];
        // append date elements to full_date
        full_date = sm[1] + "-" + sm[2] + "-" + sm[3];
       // set the second date variable
        d2 = boost::gregorian::date
           (boost::gregorian::from_simple_string(full_date));

      // store time back into the vector in hours, minutes, seconds
        hms[0] = std::stoi(sm[4]);
        hms[1] = std::stoi(sm[5]);
        hms[2] = std::stoi(sm[6]);

        end = boost::posix_time::ptime
          (d2, time_duration(hms[0], hms[1], hms[2]));

        boots += std::to_string(lines_read) + "(" + out_name + "): ";
        boots += end_date + " Boot Completed\n";

        time_difference = end - begin;

        // append boot time
        boots += "\tBoot Time: ";
        boots += std::to_string
          (time_difference.total_milliseconds()) + "ms \n\n";

        // boot successful, increment counter
        boot_successes++;
        // reset bool value to false for successful boot
        found_start = false;
       }

       // increment lines read from log
      lines_read++;
    }
    // close the log
    log.close();
  }
  boots.erase(boots.end()-1);
  rep += boots;
  // write the information to the output log.rpt file
  out << rep;
  // close it and finish
  out.close();
  return 0;
}
