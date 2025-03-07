#  מטלה מספר 1 - מימוש גרף על ידי רשימת שכנויות  
* מטרת המטלה - מחלקות, עצמים ומרחבי שמות
* הגשה ביחידים
* 

גרפים הם חלק בלתי נפרד מהתואר שלכם. במהלך הלימודים למדתם על כמה דרכים לייצוג של גרפים (מטריצת שכנויות, רשימת שכנויות ועוד).

במטלה הזאת אתם תייצגו גרף בעזרת **רשימת שכנויות** - https://en.wikipedia.org/wiki/Adjacency_list 

מטרת המטלה היא לגרום לכם להבין כיצד משתמשים ב-namespaces בשפה ואיך מנהלים את הזיכרון.

עליכם לממש את המחלקות עם המתודות הבאות:

* מחלקה בשם ``Graph`` המכילה 3 מתודות:
    - מתודה בשם ``addEdge`` - מקבלת 3 מספרים שלמים המייצגים: מקור, יעד ומשקל - המשקל הדיפולטיבי הוא 1. המתודה תוסיף צלע (לא מכוונת) לגרף
    - מתודה בשם ``removeEdge`` - מקבלת 2 מספרים שלמים המייצגים צלע ומוחקת את הצלע מהגרף. במידה והצלע לא קיימת המתודה תדפיס הודעה למסך.
    - מתודה בשם ``print_graph`` - מדפיסה את הגרף בסדר הגיוני לבחירתכם.
* מחלקה בשם ``Algorithms`` המכילה 7 מתודות:
    - מתודה בשם ``bfs_scan`` - המתודה מקבלת גרף וקודקוד התחלה ומדפיסה את הגרף לפי סריקת BFS.
    - מתודה בשם ``dfs_scan`` - המתודה מקבלת גרף וקודקוד התחלה ומדפיסה את הגרף לפי סריקת DFS.
    - מתודה בשם ``dijkstra_path`` - המתודה מקבלת גרף, קודקוד התחלה וקודקוד יעד ומדפיסה את המסלול הקצר ביותר בין 2 הקודקודים בעזרת אלגוריתם דייקסטרה.
    - מתודה בשם ``has_cycle`` - מתודה המקבלת גרף ומחזירה אמת אם ורק אם הגרף מכיל מעגל.
    - מתודה בשם ``all_paths`` - המתודה מקבלת גרף ומחזירה גרף המכיל את המשקל של המסלולים הקלים ביותר בין כל זוג קודקודים. רמז - קראו על אלגוריתם Floyd Warshall.
    - מתודה בשם ``print_mst`` - המתודה מקבלת גרף, מחשבת את העץ הפורש המינימלי בגרף ומדפיסה אותו. רמז - קראו על אלגוריתם Prim ועל אלגוריתם Kruskal.
    - מתודה בשם ``has_negative_cycle`` - המתודה מקבלת גרף ומחזירה אמת אם ורק אם הגרף מכיל מעגל שלילי.

* יש לבדוק את תקינות הקלט ולזרוק שגיאות במידת הצורך. בנוסף עליכם לכתוב טסטים לכל הפונקציות שכתבתם - מצורף קובץ בשם ``Test.cpp`` לצורך
הדגמה של בדיקות בעזרת הספרייה ``doctest``.

* מצורף גם קובץ בשם ``Demo.cpp`` המדגים את הקוד.

**שימו לב!** במטלה הזאת **אסור** להשתמש במבני נתונים של הספרייה הסטנדרטית! מבנה הנתונים היחיד שבו אתם יכולים להשתמש הוא מערך. 

* יש לבדוק שאין זליגת זיכרון בעזרת ``valgrind``.

* כתבו קובץ main שבו אתם מדגימים את הקוד שכתבתם. בנוסף, עליכם ליצור קובץ ``Makefile`` כאשר הפקודה ``make Main`` 
תריץ את הקובץ לדוגמה שכתבתם, הפקודה ``make test`` תריץ את בדיקות היחידה , והפקודה ``make valgrind`` תבדוק שאין זליגת זיכרון בעזרת valgrind.

כמו כן, עליכם לכתוב בתחילת **כל** קובץ את המייל שלכם. עליכם להגיש קובץ ``README`` המסביר את ההיררכיה של המחלקות ובאילו ספריות השתמשתם. כמו כן, עליכם לכתוב בתחילת כל קובץ את המייל שלכם.

* ב Moodle יש להגיש קובץ טקסט המורכב מ-3 שורות: בשורה הראשונה מספר תעודת הזהות שלכם, בשורה השנייה הקישור להגשה שלכם ובשורה השלישית הקומיט האחרון של הפרויקט.

מותר להתייעץ עם סטודנטים אחרים או לחפש מידע באינטרנט; אסור להעתיק קטעי-קוד שלמים מסטודנטים אחרים, מהאינטרנט וממודלי בינה מלאכותית (למשל, chatGPT).
יש לדווח על כל עזרה שקיבלתם, מסטודנטים אחרים או מהאינטרנט, בהתאם ל[תקנון היושר של המחלקה](https://www.ariel.ac.il/wp/cs/wp-content/uploads/sites/88/2020/08/Guidelines-for-Academic-Integrity.pdf).

בהצלחה!
