/**********************************************************************
 *  readme.txt template                                                   
 *  Kronos PS7a startup
 **********************************************************************/

Name: Lucas Faletra


Hours to complete assignment: 10

/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/
I think I completed the whole thing. The information being written to output
files looks correct. The instructions were very vague.


/**********************************************************************
 *  Copy here all regex's you created for parsing the file, 
 *  and explain individually what each ones does.
 **********************************************************************/
boost::regex start_regex(start_string, boost::regex::perl);
This regex is used to search for the startup message, which will be a date
followed by what looks like an IP address, and a message saying "server started"

boost::regex end_regex(end_string);
This regex is used to search for the last string of the log file which will
contain the string "oejs.AbstractConnector:Started SelectChannelConnector@0.0.0.0:9080"
to signal the device has finished booting


/**********************************************************************
 *  Describe your overall approach for solving the problem.
 *  100-200 words.
 **********************************************************************/
I created two regexes to search for the strings signaling a device has begun to
boot up and the string signaling a device has finished booting. Then I read through
the entire log, attempting to parse it with multiple conditions in the form of
if statements. I accessed the command line arguments to find out which file
I needed to read and write to. I created variables from the date class to store
the date. I used a vector to store hours minutes and seconds. Putting this all into
one main file made it very ugly to look at, but I don't really have the time
to make a full class for this program.


/**********************************************************************
 *  List whatever help (if any) you received from lab TAs,
 *  classmates, or anyone else.
 **********************************************************************/
I had help from some classmates because I could not figure out how to accomplish it at
first.

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
I had to learn what regexes are.


/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
This assignment really should have had its deadline extended. Everyone is
getting bombarded with exams, finals are coming up, and on top of that,
the portfolio is due Monday. Also, the other section with Wilkes does not
need to do this assignment and they did not have to do PS4 either. 5 days is
very unreasonable for this assignment. I also havent slept in two days. Help.
