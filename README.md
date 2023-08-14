# TextAssistant
A CLI-based project purely using C++, with the fusion of NLP and DSA, comes in handy for written English because of features like word count, uniqueness percentage, reading time, speaking time and last but not least complete summary of any English text like essays and articles.
### Abstract
To tackle the challenge of doing something related to AI(NLP) using Data Structures, we decided to do automatic extractive English text summarization. Moreover, we also implemented all data structures from scratch without using any additional libraries.
The project provides two options for input, i.e. text file or direct pasting on the console. Then it will print out the original text with all information related to it, followed by the summary of it with the number of sentences. After preprocessing the data and storing insights related to it, we used the Text rank algorithm. This algorithm finds similarities between sentences and assigns them rank. Afterwards, the algorithm will return the top-ranked of them as the summary.

---
## Run Locally

Clone the project

```bash
  git clone https://github.com/Pro-procrastinator/TextAssistant.git
```

Go to the project directory

```bash
  cd TextAssistant/
```

Build the program

```bash
  g++ Textbot.cpp -o Textbot
```

Finally, run in console

```bash
  ./Textbot
```
## Sample output

  Original Paragraph   

A student life started mostly from kindergarten then the real school life started from grade 1, and till grade 5 it is referred as primary and afterwards secondary. Higher secondary schools are known as colleges in many regions of the world. At university education become more practical and professional. At every stage different strategies are used by educational institutions to make the study more effective. Some fundamental techniques remain same throughout academic life but a number of approaches change after every phase. This is also noticeable in study strategies at college and university. College and university have many common study strategies but differences are significant regarding time, assessment and way of preparation. Time and scheduling is one of the biggest difference in college and university life. In College daily routine only consist of consecutive classes and the schedule is fixed all over the week. But, in university timetable is different every day and there are leisure hours between classes. Secondly, college academic year is of nearly 36 weeks but university academic year is divided into two 16 weeks semester. Consequently, in college administration and staff design schedule and manage time for students but in university students are totally independent for their time management. Evaluation procedures are also different in college and university. At both stages you have homework but in university homework is referred as assignment or project and deadlines for any kind of work become serious in university because teachers do not show leniency. Similarly, class tests are also present in both levels but in university it transform into quizzes and often unplanned. Another difference in assessment is marking scheme in university there is GPA (Grand Point Average) system which slightly different from normal Percentile system as it depends on the credit hours and weightage of quizzes, assignments, projects , class performance, mid exams and of course annual exams. In short your progress in every course is totally in hand of your instructor. Preparation process also cause differences between college and university. Past papers are the key to success to in college education but in university they become extinct and you have to cover complete syllabus. Additionally, there is no model paper or constant pattern of exam which is usually available in college. Furthermore, printed notes of different institutions are easily available on book shops for college subjects but in university students have to make personal notes or they just depend on slides given by the instructor. In a nutshell, preparation for tests and exams is far more difficult in university comparatively. To conclude, the main variances between college and university are of time management, assessment, and learning style. But, some fundamentals strategies remain quite same. Students are completely dependent on teachers in colleges but university provide open platform to students and they are responsible for their good and bad. 

Number of Characters : 3057       Number of Sentences : 25       Number of Words : 471 <br>
Reading Time  : 2       Speaking Time  : 3       Unique Words  : 49% 

  Summary  

College and university have many common study strategies but differences are significant regarding time, assessment and way of preparation.Time and scheduling is one of the biggest difference in college and university life.Secondly, college academic year is of nearly 36 weeks but university academic year is divided into two 16 weeks semester.Consequently, in college administration and staff design schedule and manage time for students but in university students are totally independent for their time management.

  Total Sentences :  4

## License
This project is licensed under the MIT License - click the [LICENSE](https://github.com/Pro-procrastinator/TextAssistant/blob/master/LICENSE) for details.
