Hello C,"#include <stdio.h>

int main(void)
{
    int somt;
    while (scanf(""%d"", &somt) != EOF)
    {
        switch (somt)
        {
        case 1:
            printf(""Hello C%cIn C \\n character represents a new line\n"", '\n');
            break;
        case 2:
            printf(""Hello printf%cprintf's first parameter is string representing output \""formatting\""\n"", '\n');
            break;
        case 3:
            printf(""Hello scanf%cscanf formatting string for reading a integer number is \""%%d\""\n"", '\n');
            break;
        default:
            printf(""Nesprávný vstup"");
            break;
        }
    }
    return 0;
}"
Hello C,"#include <stdio.h>

int main(void)
{
    int somt;
    while (scanf(""%d"", &somt) != EOF)
    {
        switch (somt)
        {
        case 1:
            printf(""Hello C%cIn C \\n character represents a new line\n"", '\n');
            break;
        case 2:
            printf(""Hello printf%cprintf's first parameter is string representing output \""formatting\""\n"", '\n');
            break;
        case 3:
            printf(""Hello scanf%cscanf formatting string for reading a integer number is \""%%d\""\n"", '\n');
            break;
        default:
            printf(""Nesprávný vstup\n"");
            break;
        }
    }
    return 0;
}"
Database binary search,"// get the total number of people (numOfPeople)
// get all the lines after.
// get countOfLines - total number of people (numOfPeople) ->
// -> will be comparing to this
// TODO: function which loads searched data into structs
// FIXME: Load numbers and chararrs -> maybe convert everything to int
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Data
{
  int index;
  int day;
  int month;
  int year;
  char *name;
  char *surname;
} Data;

int BinarySearch(struct Data *data, struct Data compare, int l, int r)
{
  while (l <= r)
  {
    int m = (l + (r - 1)) / 2;
    // printf("" %d "", data[m].year);
    // printf(""\n  %d   %d\n"", data[m].year, m);
    if (compare.year == data[m].year)
    {
      return m;
    }
    else if (compare.year > data[m].year)
    {
      l = m + 1;
    }
    else
    {
      r = m - 1;
    }
  }
  if (l > r)
  {
    return -1;
  }
  return -1;
}

// well, this was painful
char *getString()
{
  char *chararr = NULL;
  size_t size = 0, i = 0, j = 2;
  char c = EOF;
  while (c)
  {
    c = getc(stdin);
    if (c == EOF || c == '\n' || c == ' ')
    {
      c = 0;
    }
    if (c)
    {
      chararr = realloc(chararr, j++ * sizeof(char));
    }
    chararr[i++] = c;
  }
  chararr[i++] = '\0';
  return chararr;
}

int main()
{
  int numOfPeople;
  scanf(""%d"", &numOfPeople);
  struct Data *data = (Data *)malloc(sizeof(Data) * numOfPeople);
  int ID;
  char holder;
  for (int i = 0; i < numOfPeople; i++)
  {
    for (int e = 0; e < 5; e++)
    {
      scanf(""%d %c"", &ID, &holder);
      switch (holder)
      {
      case 'y':
        scanf(""%d"", &data[ID].year);
        // printf(""%d "", data[ID].year);
        break;
      case 'm':
        scanf(""%d"", &data[ID].month);
        // printf(""%d "", data[ID].month);
        break;
      case 'd':
        scanf(""%d"", &data[ID].day);
        // printf(""%d "", data[ID].day);
        break;
      case 'f':
        getc(stdin);
        data[ID].name = getString();
        // printf(""%s "", data[ID].name);
        break;
      case 'l':
        getc(stdin);
        data[ID].surname = getString();
        // printf(""%s "", data[ID].surname);
        break;
      default:
        // printf(""Well fuck..."");
        break;
      }
    }
    // printf(""\n"");
  }
  // printf(""\nSEARCHED\n\n"");
  struct Data compare;
  int x = 0;
  while (scanf(""%d %d %d"", &compare.year, &compare.month, &compare.day) != EOF)
  {
    // printf(""%d %d %d"", compare.year, compare.month, compare.day);
    getc(stdin);
    compare.name = getString();
    compare.surname = getString();
    // printf(""\n %d\n"", compare.year);
    int checker = BinarySearch(data, compare, 0, numOfPeople);
    if (checker == -1)
    {
      printf(""Not found\n"");
    }
    else
    {
      printf(""Found, %d %s %s\n"", checker, data[checker].name, data[checker].surname);
    }
  }
  return 0;
}
"
Database binary search,"// get the total number of people (numOfPeople)
// get all the lines after.
// get countOfLines - total number of people (numOfPeople) ->
// -> will be comparing to this
// TODO: function which loads searched data into structs
// FIXME: Load numbers and chararrs -> maybe convert everything to int
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Data
{
  int index;
  int day;
  int month;
  int year;
  char *name;
  char *surname;
} Data;

int BinarySearch(struct Data *data, struct Data compare, int l, int r)
{
  while (l <= r)
  {
    int m = (l + (r - 1)) / 2;
    // printf("" %d "", data[m].year);
    // printf(""\n  %d   %d\n"", data[m].year, m);
    if (compare.year == data[m].year)
    {
      return m;
    }
    else if (compare.year > data[m].year)
    {
      l = m + 1;
    }
    else
    {
      r = m - 1;
    }
  }
  if (l > r)
  {
    return -1;
  }
  return -1;
}

// well, this was painful
char *getString()
{
  char *chararr = NULL;
  int i = 0, j = 2;
  char c = EOF;
  while (c)
  {
    c = getc(stdin);
    if (c == EOF || c == '\n' || c == ' ')
    {
      c = 0;
    }
    if (c)
    {
      chararr = realloc(chararr, j++ * sizeof(char));
    }
    chararr[i++] = c;
  }
  chararr[i++] = '\0';
  return chararr;
}

int main()
{
  int numOfPeople;
  scanf(""%d"", &numOfPeople);
  struct Data *data = (Data *)malloc(sizeof(Data) * numOfPeople);
  int ID;
  char holder;
  for (int i = 0; i < numOfPeople; i++)
  {
    for (int e = 0; e < 5; e++)
    {
      scanf(""%d %c"", &ID, &holder);
      switch (holder)
      {
      case 'y':
        scanf(""%d"", &data[ID].year);
        break;
      case 'm':
        scanf(""%d"", &data[ID].month);
        break;
      case 'd':
        scanf(""%d"", &data[ID].day);
        break;
      case 'f':
        getc(stdin);
        data[ID].name = getString();
        break;
      case 'l':
        getc(stdin);
        data[ID].surname = getString();
        break;
      default:
        break;
      }
    }
  }
  struct Data compare;
  while (scanf(""%d %d %d"", &compare.year, &compare.month, &compare.day) != EOF)
  {
    getc(stdin);
    compare.name = getString();
    compare.surname = getString();
    int checker = BinarySearch(data, compare, 0, numOfPeople);
    if (checker == -1)
    {
      printf(""Not found\n"");
    }
    else
    {
      printf(""Found, %d %s %s\n"", checker, data[checker].name, data[checker].surname);
    }
  }
  return 0;
}
"
Database binary search,"#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Data
{
  int day;
  int month;
  int year;
  char *name;
  char *surname;
} Data;

int BinarySearch(struct Data *data, struct Data compare, int l, int r)
{
  while (l <= r)
  {
    int m = (l + (r - 1)) / 2;
    if (compare.year == data[m].year)
    {
      if (compare.month == data[m].month)
      {
        if (compare.day == data[m].day)
        {
          if (strcmp(compare.name, data[m].name) == 0)
          {
            if (strcmp(compare.surname, data[m].surname) == 0)
            {
              return m;
            }
            return -1;
          }
          return -1;
        }
        return -1;
      }
      return -1;
    }
    else if (compare.year > data[m].year)
    {
      l = m + 1;
    }
    else
    {
      r = m - 1;
    }
  }
  if (l > r)
  {
    return -1;
  }
  return -1;
}

char *getString()
{
  char *chararr = NULL;
  int i = 0, j = 2;
  char c = EOF;
  while (c)
  {
    c = getc(stdin);
    if (c == EOF || c == '\n' || c == ' ')
    {
      c = 0;
    }
    if (c)
    {
      chararr = realloc(chararr, j++ * sizeof(char));
    }
    chararr[i++] = c;
  }
  chararr[i++] = '\0';
  return chararr;
}

int main()
{
  int numOfPeople;
  scanf(""%d"", &numOfPeople);
  struct Data *data = (Data *)malloc(sizeof(Data) * numOfPeople);
  int ID;
  char holder;
  for (int i = 0; i < numOfPeople; i++)
  {
    for (int e = 0; e < 5; e++)
    {
      scanf(""%d %c"", &ID, &holder);
      switch (holder)
      {
      case 'y':
        scanf(""%d"", &data[ID].year);
        break;
      case 'm':
        scanf(""%d"", &data[ID].month);
        break;
      case 'd':
        scanf(""%d"", &data[ID].day);
        break;
      case 'f':
        getc(stdin);
        data[ID].name = getString();
        break;
      case 'l':
        getc(stdin);
        data[ID].surname = getString();
        break;
      default:
        break;
      }
    }
  }
  struct Data compare;
  while (scanf(""%d %d %d"", &compare.year, &compare.month, &compare.day) != EOF)
  {
    getc(stdin);
    compare.name = getString();
    compare.surname = getString();
    int checker = BinarySearch(data, compare, 0, numOfPeople);
    if (checker == -1)
    {
      printf(""Not found\n"");
    }
    else
    {
      printf(""Found, %d %s %s\n"", checker, data[checker].name, data[checker].surname);
    }
  }
  return 0;
}"
Database binary search,"#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Data
{
  int day;
  int month;
  int year;
  char *name;
  char *surname;
} Data;

// FIXME: if there are two instances of the same value (year), the BS will stop working.
int comparePeople(int val, int val1)
{
  if (val > val1)
  {
    return 1;
  }
  else if (val < val1)
  {
    return -1;
  }
  else
  {
    return 0;
  }
}

int BinarySearch(struct Data *data, struct Data compare, int l, int r)
{
  while (l <= r)
  {
    int m = (l + (r - 1)) / 2;
    if (comparePeople(compare.year, data[m].year) == 0)
    {
      if (comparePeople(compare.month, data[m].month) == 0)
      {
        if (comparePeople(compare.day, data[m].day) == 0)
        {
          if (strcmp(compare.name, data[m].name) == 0)
          {
            if (strcmp(compare.surname, data[m].surname) == 0)
            {
              return m;
            }
          }
        }
        else if (comparePeople(compare.day, data[m].day) > 0)
        {
          l = m + comparePeople(compare.day, data[m].day);
        }
        else if (comparePeople(compare.day, data[m].day) < 0)
        {
          r = m + comparePeople(compare.day, data[m].day);
        }
      }
      else if (comparePeople(compare.month, data[m].month) > 0)
      {
        l = m + comparePeople(compare.month, data[m].month);
      }
      else if (comparePeople(compare.month, data[m].month) < 0)
      {
        r = m + comparePeople(compare.month, data[m].month);
      }
    }
    else if (comparePeople(compare.year, data[m].year) > 0)
    {
      l = m + comparePeople(compare.year, data[m].year);
    }
    else if (comparePeople(compare.year, data[m].year) < 0)
    {
      r = m + comparePeople(compare.year, data[m].year);
    }
  }
  return -1;
}

char *getString()
{
  char *chararr = NULL;
  int i = 0, j = 2;
  char c = EOF;
  while (c)
  {
    c = getc(stdin);
    if (c == EOF || c == '\n' || c == ' ')
    {
      c = 0;
    }
    if (c)
    {
      chararr = realloc(chararr, j++ * sizeof(char));
    }
    chararr[i++] = c;
  }
  chararr[i++] = '\0';
  return chararr;
}

int main()
{
  int numOfPeople;
  scanf(""%d"", &numOfPeople);
  struct Data *data = (Data *)malloc(sizeof(Data) * numOfPeople);
  int ID;
  char holder;
  for (int i = 0; i < numOfPeople; i++)
  {
    for (int e = 0; e < 5; e++)
    {
      scanf(""%d %c"", &ID, &holder);
      switch (holder)
      {
      case 'y':
        scanf(""%d"", &data[ID].year);
        break;
      case 'm':
        scanf(""%d"", &data[ID].month);
        break;
      case 'd':
        scanf(""%d"", &data[ID].day);
        break;
      case 'f':
        getc(stdin);
        data[ID].name = getString();
        break;
      case 'l':
        getc(stdin);
        data[ID].surname = getString();
        break;
      default:
        break;
      }
    }
  }
  struct Data compare;
  while (scanf(""%d %d %d"", &compare.year, &compare.month, &compare.day) != EOF)
  {
    getc(stdin);
    compare.name = getString();
    compare.surname = getString();
    int checker = BinarySearch(data, compare, 0, numOfPeople);
    if (checker == -1)
    {
      printf(""Not found\n"");
    }
    else
    {
      printf(""Found, %d %s %s\n"", checker, data[checker].name, data[checker].surname);
    }
  }
  return 0;
}"
Database binary search,"#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Data
{
  int day;
  int month;
  int year;
  char *name;
  char *surname;
} Data;

// FIXME: if there are two instances of the same value (year), the BS will stop working.
int comparePeople(int val, int val1)
{
  if (val == val1) {
    return 0;
  }
  else if (val > val1)
  {
    return 1;
  }
  else if (val < val1)
  {
    return -1;
  }
}

int BinarySearch(struct Data *data, struct Data compare, int l, int r)
{
  while (l <= r)
  {
    int m = l + (r - l) / 2;
    if (comparePeople(compare.year, data[m].year) == 0)
    {
      if (comparePeople(compare.month, data[m].month) == 0)
      {
        if (comparePeople(compare.day, data[m].day) == 0)
        {
          if (strcmp(compare.name, data[m].name) == 0)
          {
            if (strcmp(compare.surname, data[m].surname) == 0)
            {
              return m;
            }
          }
        }
        else if (comparePeople(compare.day, data[m].day) > 0)
        {
          l = m + comparePeople(compare.day, data[m].day);
        }
        else if (comparePeople(compare.day, data[m].day) < 0)
        {
          r = m + comparePeople(compare.day, data[m].day);
        }
      }
      else if (comparePeople(compare.month, data[m].month) > 0)
      {
        l = m + comparePeople(compare.month, data[m].month);
      }
      else if (comparePeople(compare.month, data[m].month) < 0)
      {
        r = m + comparePeople(compare.month, data[m].month);
      }
    }
    else if (comparePeople(compare.year, data[m].year) > 0)
    {
      l = m + comparePeople(compare.year, data[m].year);
    }
    else if (comparePeople(compare.year, data[m].year) < 0)
    {
      r = m + comparePeople(compare.year, data[m].year);
    }
  }
  return -1;
}

char *getString()
{
  char *chararr = NULL;
  int i = 0, j = 2;
  char c = EOF;
  while (c)
  {
    c = getc(stdin);
    if (c == EOF || c == '\n' || c == ' ')
    {
      c = 0;
    }
    if (c)
    {
      chararr = realloc(chararr, j++ * sizeof(char));
    }
    chararr[i++] = c;
  }
  chararr[i++] = '\0';
  return chararr;
}

int main()
{
  int numOfPeople;
  scanf(""%d"", &numOfPeople);
  struct Data *data = (Data *)malloc(sizeof(Data) * numOfPeople);
  int ID;
  char holder;
  for (int i = 0; i < numOfPeople; i++)
  {
    for (int e = 0; e < 5; e++)
    {
      scanf(""%d %c"", &ID, &holder);
      switch (holder)
      {
      case 'y':
        scanf(""%d"", &data[ID].year);
        break;
      case 'm':
        scanf(""%d"", &data[ID].month);
        break;
      case 'd':
        scanf(""%d"", &data[ID].day);
        break;
      case 'f':
        getc(stdin);
        data[ID].name = getString();
        break;
      case 'l':
        getc(stdin);
        data[ID].surname = getString();
        break;
      default:
        break;
      }
    }
  }
  struct Data compare;
  while (scanf(""%d %d %d"", &compare.year, &compare.month, &compare.day) != EOF)
  {
    getc(stdin);
    compare.name = getString();
    compare.surname = getString();
    int checker = BinarySearch(data, compare, 0, numOfPeople);
    if (checker == -1)
    {
      printf(""Not found\n"");
    }
    else
    {
      printf(""Found, %d %s %s\n"", checker, data[checker].name, data[checker].surname);
    }
  }
  return 0;
}"
Database binary search,"#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Data
{
  int day;
  int month;
  int year;
  char *name;
  char *surname;
} Data;

// FIXME: if there are two instances of the same value (year), the BS will stop working.
// int comparePeople(int val, int val1)
// {
//   if (val == val1) {
//     return 0;
//   }
//   else if (val > val1)
//   {
//     return 1;
//   }
//   else if (val < val1)
//   {
//     return -1;
//   }
// }

int BinarySearch(struct Data *data, struct Data compare, int l, int r)
{
  while (l <= r)
  {
    int m = l + (r - l) / 2;
    if (compare.year == data[m].year)
    {
      if (compare.month == data[m].month)
      {
        if (compare.day == data[m].day)
        {
          if (strcmp(compare.name, data[m].name) == 0)
          {
            if (strcmp(compare.surname, data[m].surname) == 0)
            {
              return m;
            }
            return -1;
          }
          return -1;
        }
        return -1;
      }
      return -1;
    }
    else if (compare.year > data[m].year)
    {
      l = m + 1;
    }
    else
    {
      r = m - 1;
    }
  }
  if (l > r)
  {
    return -1;
  }
  return -1;
}


char *getString()
{
  char *chararr = NULL;
  int i = 0, j = 2;
  char c = EOF;
  while (c)
  {
    c = getc(stdin);
    if (c == EOF || c == '\n' || c == ' ')
    {
      c = 0;
    }
    if (c)
    {
      chararr = realloc(chararr, j++ * sizeof(char));
    }
    chararr[i++] = c;
  }
  chararr[i++] = '\0';
  return chararr;
}

int main()
{
  int numOfPeople;
  scanf(""%d"", &numOfPeople);
  struct Data *data = (Data *)malloc(sizeof(Data) * numOfPeople);
  int ID;
  char holder;
  for (int i = 0; i < numOfPeople; i++)
  {
    for (int e = 0; e < 5; e++)
    {
      scanf(""%d %c"", &ID, &holder);
      switch (holder)
      {
      case 'y':
        scanf(""%d"", &data[ID].year);
        break;
      case 'm':
        scanf(""%d"", &data[ID].month);
        break;
      case 'd':
        scanf(""%d"", &data[ID].day);
        break;
      case 'f':
        getc(stdin);
        data[ID].name = getString();
        break;
      case 'l':
        getc(stdin);
        data[ID].surname = getString();
        break;
      default:
        break;
      }
    }
  }
  struct Data compare;
  while (scanf(""%d %d %d"", &compare.year, &compare.month, &compare.day) != EOF)
  {
    getc(stdin);
    compare.name = getString();
    compare.surname = getString();
    int checker = BinarySearch(data, compare, 0, numOfPeople);
    if (checker == -1)
    {
      printf(""Not found\n"");
    }
    else
    {
      printf(""Found, %d %s %s\n"", checker, data[checker].name, data[checker].surname);
    }
  }
  return 0;
}"
Database binary search,"#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Data
{
  int day;
  int month;
  int year;
  char *name;
  char *surname;
} Data;

// FIXME: if there are two instances of the same value (year), the BS will stop working.
int comparePeople(int val, int val1)
{
  if (val == val1)
  {
    return 0;
  }
  else if (val > val1)
  {
    return 1;
  }
  else if (val < val1)
  {
    return -1;
  }
}

int BinarySearch(struct Data *data, struct Data compare, int l, int r)
{
  while (l <= r)
  {
    int m = l + (r - l) / 2;
    int comparePeopleYear = comparePeople(compare.year, data[m].year);
    if (comparePeopleYear == 0)
    {
      int comparePeopleMonth = comparePeople(compare.month, data[m].month);
      if (comparePeopleMonth == 0)
      {
        int comparePeopleDay = comparePeople(compare.day, data[m].day);
        if (comparePeopleDay == 0)
        {
          if (strcmp(compare.name, data[m].name) == 0)
          {
            if (strcmp(compare.surname, data[m].surname) == 0)
            {
              return m;
            }
          }
        }
        else if (comparePeopleDay > 0)
        {
          l = m + comparePeopleDay;
        }
        else if (comparePeopleDay < 0)
        {
          r = m + comparePeopleDay;
        }
      }
      else if (comparePeopleMonth > 0)
      {
        l = m + comparePeopleMonth;
      }
      else if (comparePeopleMonth < 0)
      {
        r = m + comparePeopleMonth;
      }
    }
    else if (comparePeopleYear > 0)
    {
      l = m + comparePeopleYear;
    }
    else if (comparePeopleYear < 0)
    {
      r = m + comparePeopleYear;
    }
  }
  return -1;
}

char *getString()
{
  char *chararr = NULL;
  int i = 0, j = 2;
  char c = EOF;
  while (c)
  {
    c = getc(stdin);
    if (c == EOF || c == '\n' || c == ' ')
    {
      c = 0;
    }
    if (c)
    {
      chararr = realloc(chararr, j++ * sizeof(char));
    }
    chararr[i++] = c;
  }
  chararr[i++] = '\0';
  return chararr;
}

int main()
{
  int numOfPeople;
  scanf(""%d"", &numOfPeople);
  struct Data *data = (Data *)malloc(sizeof(Data) * numOfPeople);
  int ID;
  char holder;
  for (int i = 0; i < numOfPeople; i++)
  {
    for (int e = 0; e < 5; e++)
    {
      scanf(""%d %c"", &ID, &holder);
      switch (holder)
      {
      case 'y':
        scanf(""%d"", &data[ID].year);
        break;
      case 'm':
        scanf(""%d"", &data[ID].month);
        break;
      case 'd':
        scanf(""%d"", &data[ID].day);
        break;
      case 'f':
        getc(stdin);
        data[ID].name = getString();
        break;
      case 'l':
        getc(stdin);
        data[ID].surname = getString();
        break;
      default:
        break;
      }
    }
  }
  struct Data compare;
  while (scanf(""%d %d %d"", &compare.year, &compare.month, &compare.day) != EOF)
  {
    getc(stdin);
    compare.name = getString();
    compare.surname = getString();
    int checker = BinarySearch(data, compare, 0, numOfPeople);
    if (checker == -1)
    {
      printf(""Not found\n"");
    }
    else
    {
      printf(""Found, %d %s %s\n"", checker, data[checker].name, data[checker].surname);
    }
  }
  return 0;
}"
Database binary search,"#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Data
{
  int day;
  int month;
  int year;
  char *name;
  char *surname;
} Data;

// FIXME: if there are two instances of the same value (year), the BS will stop working.
int comparePeople(int val, int val1)
{
  if (val == val1)
  {
    return 0;
  }
  else if (val > val1)
  {
    return 1;
  }
  else
  {
    return -1;
  }
}

int BinarySearch(struct Data *data, struct Data compare, int l, int r)
{
  while (l <= r)
  {
    int m = l + (r - l) / 2;
    int comparePeopleYear = comparePeople(compare.year, data[m].year);
    if (comparePeopleYear == 0)
    {
      int comparePeopleMonth = comparePeople(compare.month, data[m].month);
      if (comparePeopleMonth == 0)
      {
        int comparePeopleDay = comparePeople(compare.day, data[m].day);
        if (comparePeopleDay == 0)
        {
          int comparePeopleName = strcmp(compare.name, data[m].name);
          if (comparePeopleName == 0)
          {
            int comparePeopleSurname = strcmp(compare.surname, data[m].surname);
            if (comparePeopleSurname== 0)
            {
              return m;
            }
            else if (comparePeopleSurname < 0)
            {
              l = m + 1;
            }
            else if (comparePeopleSurname > 0)
            {
              r = m - 1;
            }
          }
          else if (comparePeopleName < 0)
          {
            r = m - 1;
          }
          else if (comparePeopleName > 0)
          {
            l = m + 1;
          }
        }
        else if (comparePeopleDay > 0)
        {
          l = m + comparePeopleDay;
        }
        else if (comparePeopleDay < 0)
        {
          r = m + comparePeopleDay;
        }
      }
      else if (comparePeopleMonth > 0)
      {
        l = m + comparePeopleMonth;
      }
      else if (comparePeopleMonth < 0)
      {
        r = m + comparePeopleMonth;
      }
    }
    else if (comparePeopleYear > 0)
    {
      l = m + comparePeopleYear;
    }
    else if (comparePeopleYear < 0)
    {
      r = m + comparePeopleYear;
    }
  }
  return -1;
}

char *getString()
{
  char *chararr = NULL;
  int i = 0, j = 2;
  char c = EOF;
  while (c)
  {
    c = getc(stdin);
    if (c == EOF || c == '\n' || c == ' ')
    {
      c = 0;
    }
    if (c)
    {
      chararr = realloc(chararr, j++ * sizeof(char));
    }
    chararr[i++] = c;
  }
  chararr[i++] = '\0';
  return chararr;
}

int main()
{
  int numOfPeople;
  scanf(""%d"", &numOfPeople);
  struct Data *data = (Data *)malloc(sizeof(Data) * numOfPeople);
  int ID;
  char holder;
  for (int i = 0; i < numOfPeople; i++)
  {
    for (int e = 0; e < 5; e++)
    {
      scanf(""%d %c"", &ID, &holder);
      switch (holder)
      {
      case 'y':
        scanf(""%d"", &data[ID].year);
        break;
      case 'm':
        scanf(""%d"", &data[ID].month);
        break;
      case 'd':
        scanf(""%d"", &data[ID].day);
        break;
      case 'f':
        getc(stdin);
        data[ID].name = getString();
        break;
      case 'l':
        getc(stdin);
        data[ID].surname = getString();
        break;
      default:
        break;
      }
    }
  }
  struct Data compare;
  while (scanf(""%d %d %d"", &compare.year, &compare.month, &compare.day) != EOF)
  {
    getc(stdin);
    compare.name = getString();
    compare.surname = getString();
    int checker = BinarySearch(data, compare, 0, numOfPeople);
    if (checker == -1)
    {
      printf(""Not found\n"");
    }
    else
    {
      printf(""Found, %d %s %s\n"", checker, data[checker].name, data[checker].surname);
    }
  }
  return 0;
}"
Database binary search,"#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Data
{
  int day;
  int month;
  int year;
  char *name;
  char *surname;
} Data;

// FIXME: if there are two instances of the same value (year), the BS will stop working.
int comparePeople(int val, int val1)
{
  if (val == val1)
  {
    return 0;
  }
  else if (val > val1)
  {
    return 1;
  }
  else
  {
    return -1;
  }
}

int BinarySearch(struct Data *data, struct Data compare, int l, int r)
{
  while (l <= r)
  {
    int m = l + (r - l) / 2;
    int comparePeopleYear = comparePeople(compare.year, data[m].year);
    if (comparePeopleYear == 0)
    {
      int comparePeopleMonth = comparePeople(compare.month, data[m].month);
      if (comparePeopleMonth == 0)
      {
        int comparePeopleDay = comparePeople(compare.day, data[m].day);
        if (comparePeopleDay == 0)
        {
          int comparePeopleName = strcmp(compare.name, data[m].name);
          if (comparePeopleName == 0)
          {
            int comparePeopleSurname = strcmp(compare.surname, data[m].surname);
            if (comparePeopleSurname == 0)
            {
              return m;
            }
            else if (comparePeopleSurname < 0)
            {
              l = m + 1;
            }
            else if (comparePeopleSurname > 0)
            {
              r = m - 1;
            }
          }
          else if (comparePeopleName < 0)
          {
            r = m - 1;
          }
          else if (comparePeopleName > 0)
          {
            l = m + 1;
          }
        }
        else if (comparePeopleDay > 0)
        {
          l = m + comparePeopleDay;
        }
        else if (comparePeopleDay < 0)
        {
          r = m + comparePeopleDay;
        }
      }
      else if (comparePeopleMonth > 0)
      {
        l = m + comparePeopleMonth;
      }
      else if (comparePeopleMonth < 0)
      {
        r = m + comparePeopleMonth;
      }
    }
    else if (comparePeopleYear > 0)
    {
      l = m + comparePeopleYear;
    }
    else if (comparePeopleYear < 0)
    {
      r = m + comparePeopleYear;
    }
  }
  return -1;
}

char *getString()
{
  char *chararr = NULL;
  int i = 0, j = 2;
  char c = EOF;
  while (c)
  {
    c = getc(stdin);
    if (c == EOF || c == '\n' || c == ' ')
    {
      c = 0;
    }
    if (c)
    {
      chararr = realloc(chararr, j++ * sizeof(char));
    }
    chararr[i++] = c;
  }
  chararr[i++] = '\0';
  return chararr;
}

int main()
{
  int numOfPeople;
  scanf(""%d"", &numOfPeople);
  struct Data *data = (Data *)malloc(sizeof(Data) * numOfPeople);
  int ID;
  char holder;
  for (int i = 0; i < numOfPeople; i++)
  {
    for (int e = 0; e < 5; e++)
    {
      scanf(""%d %c"", &ID, &holder);
      switch (holder)
      {
      case 'y':
        scanf(""%d"", &data[ID].year);
        break;
      case 'm':
        scanf(""%d"", &data[ID].month);
        break;
      case 'd':
        scanf(""%d"", &data[ID].day);
        break;
      case 'f':
        getc(stdin);
        data[ID].name = getString();
        break;
      case 'l':
        getc(stdin);
        data[ID].surname = getString();
        break;
      default:
        break;
      }
    }
  }
  struct Data compare;
  while (scanf(""%d %d %d"", &compare.year, &compare.month, &compare.day) != EOF)
  {
    getc(stdin);
    compare.name = getString();
    compare.surname = getString();
    int checker = BinarySearch(data, compare, 0, numOfPeople);
    if (checker == -1)
    {
      printf(""Not found\n"");
    }
    else
    {
      printf(""Found, %d %s %s\n"", checker, data[checker].name, data[checker].surname);
    }
  }
  return 0;
}"
Database binary search,"#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Data
{
  int day;
  int month;
  int year;
  char *name;
  char *surname;
} Data;

// FIXME: if there are two instances of the same value (year), the BS will stop working.
int comparePeople(int val, int val1)
{
  if (val == val1)
  {
    return 0;
  }
  else if (val > val1)
  {
    return 1;
  }
  else
  {
    return -1;
  }
}

int BinarySearch(struct Data *data, struct Data compare, int l, int r)
{
  while (l <= r)
  {
    int m = l + (r - l) / 2;
    int comparePeopleYear = comparePeople(compare.year, data[m].year);
    if (comparePeopleYear == 0)
    {
      int comparePeopleMonth = comparePeople(compare.month, data[m].month);
      if (comparePeopleMonth == 0)
      {
        int comparePeopleDay = comparePeople(compare.day, data[m].day);
        if (comparePeopleDay == 0)
        {
          int comparePeopleName = strcmp(compare.name, data[m].name);
          if (comparePeopleName == 0)
          {
            int comparePeopleSurname = strcmp(compare.surname, data[m].surname);
            if (comparePeopleSurname == 0)
            {
              return m;
            }
            else if (comparePeopleSurname < 0)
            {
              r = m - 1;
            }
            else if (comparePeopleSurname > 0)
            {
              l = m + 1;
            }
          }
          else if (comparePeopleName < 0)
          {
            r = m - 1;
          }
          else if (comparePeopleName > 0)
          {
            l = m + 1;
          }
        }
        else if (comparePeopleDay > 0)
        {
          l = m + comparePeopleDay;
        }
        else if (comparePeopleDay < 0)
        {
          r = m + comparePeopleDay;
        }
      }
      else if (comparePeopleMonth > 0)
      {
        l = m + comparePeopleMonth;
      }
      else if (comparePeopleMonth < 0)
      {
        r = m + comparePeopleMonth;
      }
    }
    else if (comparePeopleYear > 0)
    {
      l = m + comparePeopleYear;
    }
    else if (comparePeopleYear < 0)
    {
      r = m + comparePeopleYear;
    }
  }
  return -1;
}

char *getString()
{
  char *chararr = NULL;
  int i = 0, j = 2;
  char c = EOF;
  while (c)
  {
    c = getc(stdin);
    if (c == EOF || c == '\n' || c == ' ')
    {
      c = 0;
    }
    if (c)
    {
      chararr = realloc(chararr, j++ * sizeof(char));
    }
    chararr[i++] = c;
  }
  chararr[i++] = '\0';
  return chararr;
}

int main()
{
  int numOfPeople;
  scanf(""%d"", &numOfPeople);
  struct Data *data = (Data *)malloc(sizeof(Data) * numOfPeople);
  int ID;
  char holder;
  for (int i = 0; i < numOfPeople; i++)
  {
    for (int e = 0; e < 5; e++)
    {
      scanf(""%d %c"", &ID, &holder);
      switch (holder)
      {
      case 'y':
        scanf(""%d"", &data[ID].year);
        break;
      case 'm':
        scanf(""%d"", &data[ID].month);
        break;
      case 'd':
        scanf(""%d"", &data[ID].day);
        break;
      case 'f':
        getc(stdin);
        data[ID].name = getString();
        break;
      case 'l':
        getc(stdin);
        data[ID].surname = getString();
        break;
      default:
        break;
      }
    }
  }
  struct Data compare;
  while (scanf(""%d %d %d"", &compare.year, &compare.month, &compare.day) != EOF)
  {
    getc(stdin);
    compare.name = getString();
    compare.surname = getString();
    int checker = BinarySearch(data, compare, 0, numOfPeople);
    if (checker == -1)
    {
      printf(""Not found\n"");
    }
    else
    {
      printf(""Found, %d %s %s\n"", checker, data[checker].name, data[checker].surname);
    }
  }
  return 0;
}"
Bubble sort,"#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number;
    int j = 1, i = 0;
    int *numberArray = (int *)malloc(1);
    while (scanf(""%d"", &number) != EOF)
    {
        numberArray = (int *)realloc(numberArray, j++ * sizeof(int));
        numberArray[i] = number;
        i++;
    }
    for (int f = 0; f < i; f++)
    {
        for (int e = 0; e < i - f; e++)
        {
            if (numberArray[e] > numberArray[e + 1])
            {
                int temp = numberArray[e];
                numberArray[e] = numberArray[e + 1];
                numberArray[e + 1] = temp;
            }
        }
    }
    for (int o = 0; o < i; o++)
    {
        printf(""%d\n"", numberArray[o]);
    }
}"
Insertion sort,"#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number;
    int j = 1, i = 0;
    int *numberArray = (int *)malloc(1);
    while (scanf(""%d"", &number) != EOF)
    {
        numberArray = (int *)realloc(numberArray, j++ * sizeof(int));
        numberArray[i] = number;
        i++;
    }
    for (int f = 0; f < i; f++)
    {
        if (f != 0) {
            if (numberArray[f-1] > numberArray[f]) {
                int counter = f;
                while (numberArray[counter-1] > numberArray[counter]) {
                    int temp = numberArray[counter];
                    numberArray[counter] = numberArray[counter-1];
                    numberArray[counter-1] = temp;
                    counter--;
                }
            }
        } 
    }
    for (int o = 0; o < i; o++)
    {
        printf(""%d\n"", numberArray[o]);
    }
}"
Bubble sort,"#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number;
    int j = 1, i = 0;
    int *numberArray = (int *)malloc(1);
    while (scanf(""%d"", &number) != EOF)
    {
        numberArray = (int *)realloc(numberArray, j++ * sizeof(int));
        numberArray[i] = number;
        i++;
    }
    for (int f = 0; f < i; f++)
    {
        for (int e = 0; e < i - f - 1; e++)
        {
            if (numberArray[e] > numberArray[e + 1])
            {
                int temp = numberArray[e];
                numberArray[e] = numberArray[e + 1];
                numberArray[e + 1] = temp;
            }
        }
    }
    for (int o = 0; o < i; o++)
    {
        printf(""%d\n"", numberArray[o]);
    }
}"
Insertion sort,"#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number;
    int j = 1, i = 0;
    int *numberArray = (int *)malloc(1);
    while (scanf(""%d"", &number) != EOF)
    {
        numberArray = (int *)realloc(numberArray, j++ * sizeof(int));
        numberArray[i] = number;
        i++;
        for (int f = i - 1; f >= 0; f--)
        {
            if (numberArray[f - 1] > numberArray[f])
            {
                int counter = f;
                while (numberArray[counter - 1] > numberArray[counter])
                {
                    int temp = numberArray[counter];
                    numberArray[counter] = numberArray[counter - 1];
                    numberArray[counter - 1] = temp;
                    counter--;
                }
            }
        }
    }
    for (int o = 0; o < i; o++)
    {
        printf(""%d\n"", numberArray[o]);
    }
}"
Selection sort,"#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number;
    int j = 1, i = 0;
    int *numberArray = (int *)malloc(1);
    while (scanf(""%d"", &number) != EOF)
    {
        numberArray = (int *)realloc(numberArray, j++ * sizeof(int));
        numberArray[i] = number;
        i++;
    }
    int minimum;
    int currentItem;
    for (int f = 0; f < i; f++)
    {
        currentItem = numberArray[f];
        minimum = numberArray[f];
        int minIndex;
        for (int e = f; e < i; e++)
        {
            if (numberArray[e] < minimum)
            {
                minimum = numberArray[e];
                minIndex = e;
            }
        }
        if (numberArray[f] > minimum) {
            int temp = numberArray[f];
            numberArray[f] = minimum;
            numberArray[minIndex] = temp;
        }
    }
    for (int o = 0; o < i; o++)
    {
        printf(""%d\n"", numberArray[o]);
    }
}"
Insertion sort,"#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number;
    int j = 1, i = 0;
    int *numberArray = (int *)malloc(2);
    while (scanf(""%d"", &number) != EOF)
    {
        numberArray = (int *)realloc(numberArray, j++ * sizeof(int));
        numberArray[i] = number;
        i++;
        for (int f = i - 1; f > 0; f--)
        {
            if (numberArray[f - 1] > numberArray[f])
            {
                int counter = f;
                while (numberArray[counter - 1] > numberArray[counter])
                {
                    int temp = numberArray[counter];
                    numberArray[counter] = numberArray[counter - 1];
                    numberArray[counter - 1] = temp;
                    counter--;
                    if (counter == 0)
                    {
                        break;
                    }
                }
            }
        }
    }
    for (int o = 0; o < i; o++)
    {
        printf(""%d\n"", numberArray[o]);
    }
    return 0;
}"
Insertion sort,"#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number, counter, temp;
    int j = 1, i = 0;
    int *numberArray = (int *)malloc(0);
    while (scanf(""%d"", &number) != EOF)
    {
        numberArray = (int *)realloc(numberArray, j++ * sizeof(int));
        numberArray[i] = number;
        i++;
        for (int f = i - 1; f > 0; f--)
        {
            if (numberArray[f - 1] > numberArray[f])
            {
                counter = f;
                while (numberArray[counter - 1] > numberArray[counter] && counter > 0)
                {
                    temp = numberArray[counter];
                    numberArray[counter] = numberArray[counter - 1];
                    numberArray[counter - 1] = temp;
                    counter--;
                }
            }
        }
    }
    for (int o = 0; o < i; o++)
    {
        printf(""%d\n"", numberArray[o]);
    }
    return 0;
}"
Insertion sort,"#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number, counter, temp;
    int j = 1, i = 0;
    int *numberArray = (int *)malloc(0);
    while (scanf(""%d"", &number) != EOF)
    {
        numberArray = (int *)realloc(numberArray, j++ * sizeof(int));
        numberArray[i] = number;
        i++;
        for (int f = 1; f < i; f++)
        {
            if (numberArray[f - 1] > numberArray[f])
            {
                counter = f;
                while (numberArray[counter - 1] > numberArray[counter] && counter > 0)
                {
                    temp = numberArray[counter];
                    numberArray[counter] = numberArray[counter - 1];
                    numberArray[counter - 1] = temp;
                    counter--;
                }
            }
        }
    }
    for (int o = 0; o < i; o++)
    {
        printf(""%d\n"", numberArray[o]);
    }
    return 0;
}"
Insertion sort,"#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number, counter, temp;
    int j = 1, i = 0;
    int *numberArray = (int *)malloc(1);
    while (scanf(""%d"", &number) != EOF)
    {
        numberArray = (int *)realloc(numberArray, j++ * sizeof(int));
        numberArray[i] = number;
        i++;
    }
    for (int f = 1; f < i; f++)
    {
        if (numberArray[f - 1] > numberArray[f])
        {
            counter = f;
            while (numberArray[counter - 1] > numberArray[counter] && counter > 0)
            {
                temp = numberArray[counter];
                numberArray[counter] = numberArray[counter - 1];
                numberArray[counter - 1] = temp;
                counter--;
            }
        }
    }
    for (int o = 0; o < i; o++)
    {
        printf(""%d\n"", numberArray[o]);
    }
    return 0;
}"
Tree parsing and in-order traversal,"// THIS CODE DOES NOT WORK FULLY, I DO NOT EXPECT IT TO WORK
#include <stdio.h>
#include <stdlib.h>

#define NULL ((void *)0)

struct Node {
    int value;
    struct Node *leftNode;
    struct Node *rightNode;
};

// Creates a new node
struct Node *createNewNode(int value) {
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    node->value = value;
    node->leftNode = NULL;
    node->rightNode = NULL;

    return node;
}

// Prints the node tree in order
void printTreeInOrder(struct Node *node) {
    if (node == NULL)
        return;

    printTreeInOrder(node->leftNode);
    printf(""%d\n"", node->value);
    printTreeInOrder(node->rightNode);
}

// Loads values and the current node tree, creates new nodes on current leaves
struct Node *fillIntoRoot(struct Node *node, int value, int side) {
    //struct Node *node = tree;
    // Creates a new node on the left side
    if (side) {
        return node->leftNode = createNewNode(value);
    }
        // Creates a new node on the right side
    else {
        return node->rightNode = createNewNode(value);
    }
}

int main() {
    // Value for the root node
    int rootValue = (int) (getc(stdin) - '0');
    // Creating the root node
    struct Node *root = createNewNode(rootValue);
    // HELPER VARIABLES
    // --> Current character
    char chCurrentValue;
    // --> Current value
    int currentValue = 0;
    // --> Determining side of the node
    int isLeft = 1;
    while (scanf(""%c"", &chCurrentValue) != EOF) {
        // Guard statement
        if (chCurrentValue == '\n' || chCurrentValue == ' ') continue;

        // Loading value
        if (chCurrentValue >= 48 && chCurrentValue <= 57) {
            currentValue = (int) chCurrentValue - '0';
        }

        // Determining node side
        if (chCurrentValue == '{') {
            isLeft = 1;
        } else if (chCurrentValue == '[') {
            isLeft = 0;
        }
        if (chCurrentValue == '}') {
            isLeft = 0;
        } else if (chCurrentValue == ']') {
            isLeft = 1;
        }

        // Creating nodes on corresponding sides with corresponding values
        // --> [Bug] It obviously overwrites right now, :(
        root = fillIntoRoot(root, currentValue, isLeft);
    }
    printTreeInOrder(root);
    return 0;
}
"
Tree parsing and in-order traversal,"#include <stdio.h>
#include <stdlib.h>

#define NULL ((void *)0)

struct Node {
    int value;
    struct Node *leftNode;
    struct Node *rightNode;
};

// Creates a new node
struct Node *createNewNode(int value) {
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    node->value = value;
    node->leftNode = NULL;
    node->rightNode = NULL;

    return node;
}

// Prints the node tree in order
void printTreeInOrder(struct Node *node) {
    if (node == NULL)
        return;

    printTreeInOrder(node->leftNode);
    printf(""%d\n"", node->value);
    printTreeInOrder(node->rightNode);
}

char loadCharacter() {
    char value = getc(stdin);
    while (value == '\n' || value == ' ' || value == '\t') {
        value = getc(stdin);
    }
    return value;
}

struct Node *fillIntoNode(struct Node *node, int left) {
    // Create a new node with the passed node
    struct Node *currentNode = node;
    char currentCharacter = loadCharacter();

    if (left) {
        // Left scope
        currentNode->leftNode = createNewNode((int) (currentCharacter - '0'));
        currentCharacter = loadCharacter();
        // ending 
        if (currentCharacter == '}') {
            return currentNode;
        } else if (currentCharacter == ']') {
            // syntax error, I am not handling this just yet
            return currentNode;
        }

        // opening
        if (currentCharacter == '{') {
            // recursion on the left node
            left = 1;
            currentNode->leftNode->leftNode = fillIntoNode(currentNode->leftNode, left);
        } else if (currentCharacter == '[') {
            // recursion on the right node
            left = 0;
            currentNode->rightNode->rightNode = fillIntoNode(currentNode->rightNode, left);
        }
    } else {
        // Right scope
        currentNode->rightNode = createNewNode((int) (currentCharacter - '0'));
        currentCharacter = loadCharacter();
        // ending 
        if (currentCharacter == ']') {
            return currentNode;
        } else if (currentCharacter == '}') {
            // syntax error, I am not handling this just yet
            return currentNode;
        }

        // opening
        if (currentCharacter == '{') {
            // recursion on the left node
            left = 1;
            currentNode->rightNode->leftNode = fillIntoNode(currentNode->leftNode, left);
        } else if (currentCharacter == '[') {
            // recursion on the right node
            left = 0;
            currentNode->rightNode->rightNode = fillIntoNode(currentNode->rightNode, left);

        }
    }
}

struct Node *createTree(struct Node *root) {
    char currentCharacter = ' ';
    int isLeft;
        while (currentCharacter != EOF) {
        currentCharacter = loadCharacter();

        if (currentCharacter == '{') {
            isLeft = 1;
            root = fillIntoNode(root, isLeft);
            //return root;

        } else if (currentCharacter == '[') {
            // do something when right scope
            isLeft = 0;
            root = fillIntoNode(root, isLeft);
        }

        if (currentCharacter == '}') {
            // do something when left scope ends
        } else if (currentCharacter == ']') {
            // do something when right scope ends
        }

    }
    return root;
}

int main() {
// create root node, recursively add values to nodes
// determine if the scope is left or right
// check for closing brackets (closing scopes)
    struct Node *root = createNewNode((int) (loadCharacter() - '0'));
    //printf(""%d"", root->value);
    root = createTree(root);
    printTreeInOrder(root);
    return 0;
}


// Validating the functionality of my createNewNode() function on this
//    struct Node *root = createNewNode(1);
//    root->leftNode = createNewNode(1);
//    root->rightNode = createNewNode(2);
//    root->leftNode->leftNode = createNewNode(3);
//    printTreeInOrder(root);
"
Tree parsing and in-order traversal,"#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define NULL ((void *)0)

struct Node {
    int value;
    struct Node *leftNode;
    struct Node *rightNode;
};

// Creates a new node
struct Node *createNewNode(int value) {
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    node->value = value;
    node->leftNode = NULL;
    node->rightNode = NULL;

    return node;
}

// Prints the node tree in order
void printTreeInOrder(struct Node *node) {
    if (node == NULL)
        return;

    printTreeInOrder(node->leftNode);
    printf(""%d\n"", node->value);
    printTreeInOrder(node->rightNode);
}

char loadCharacter() {
    char charValue = getc(stdin);
    while (charValue == '\n' || charValue == ' ' || charValue == '\t') {
        charValue = getc(stdin);
    }
    return charValue;
}

int loadInteger() {
    int intValue;
    scanf(""%d"", &intValue);
    return intValue;
}

struct Node *fillIntoNode(struct Node *node, char scope) {
    if (scope == ' ') {
        scope = loadCharacter();
    }

    // ending 
    if (scope == '}') {
        return node;
    } else if (scope == ']') {
        // syntax error, I am not handling this just yet
        return node;
    }

    int value = loadInteger();

    if (isdigit(value)) {
        printf(""%c ERROR"", scope);
    }

    //currentNode = createNewNode(value);
    node = createNewNode(value);

    // opening
    if (scope == '{') {
        // recursion on the left node
        node->leftNode = createNewNode(NULL);
        node->leftNode = fillIntoNode(node->leftNode, ' ');
    } else if (scope == '[') {
        // recursion on the right node
        node->rightNode = createNewNode(NULL);
        node->rightNode = fillIntoNode(node->rightNode, ' ');
    }

    scope = loadCharacter();

    // ending 
    if (scope == '}') {
        return node;
    } else if (scope == ']') {
        // syntax error, I am not handling this just yet
        return node;
    }

    // opening
    if (scope == '{') {
        // recursion on the left node
        node->leftNode = createNewNode(NULL);
        node->leftNode = fillIntoNode(node->leftNode, '{');
    } else if (scope == '[') {
        // recursion on the right node
        node->rightNode = createNewNode(NULL);
        node->rightNode = fillIntoNode(node->rightNode, '[');
    }
    return node;
}

int main() {
// create root node, recursively add values to nodes
// determine if the scope is left or right
// check for closing brackets (closing scopes)
    struct Node *root = createNewNode((int) (loadCharacter() - '0'));
    //printf(""%d"", root->value);
    root->leftNode = fillIntoNode(root, '{');
    root->rightNode = fillIntoNode(root, '[');
    printTreeInOrder(root);
    return 0;
}


// Validating the functionality of my createNewNode() function on this
//    struct Node *root = createNewNode(1);
//    root->leftNode = createNewNode(1);
//    root->rightNode = createNewNode(2);
//    root->leftNode->leftNode = createNewNode(3);
//    printTreeInOrder(root);
"
Tree parsing and in-order traversal,"#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define NULL ((void *)0)

struct Node {
    int value;
    struct Node *leftNode;
    struct Node *rightNode;
};

// Creates a new node
struct Node *createNewNode(int value) {
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    node->value = value;
    node->leftNode = NULL;
    node->rightNode = NULL;

    return node;
}

// Prints the node tree in order
void printTreeInOrder(struct Node *node) {
    if (node == NULL)
        return;

    printTreeInOrder(node->leftNode);
    printf(""%d\n"", node->value);
    printTreeInOrder(node->rightNode);
}

char loadCharacter() {
    char charValue = getc(stdin);
    while (charValue == '\n' || charValue == ' ' || charValue == '\t') {
        charValue = getc(stdin);
    }
    return charValue;
}

int loadInteger() {
    int intValue;
    scanf(""%d"", &intValue);
    return intValue;
    // 48 - 57
}

struct Node *fillIntoNode(struct Node *node, char scope) {
    if (scope == ' ') {
        scope = loadCharacter();
    }
    
    if (scope != '[' && scope != '{' && scope != ']' && scope != '}') {
        return node->value = NULL;
    }

    // ending 
    if (scope == '}') {
        return node->value = NULL;
    } else if (scope == ']') {
        // syntax error, I am not handling this just yet
        return node->value = NULL;
    }

    int value = loadInteger();

    if (isdigit(value)) {
        printf(""%c ERROR"", scope);
    }

    //currentNode = createNewNode(value);
    node = createNewNode(value);

    // opening
    if (scope == '{') {
        // recursion on the left node
        node->leftNode = createNewNode(value);
        node->leftNode = fillIntoNode(node->leftNode, ' ');
    } else if (scope == '[') {
        // recursion on the right node
        node->rightNode = createNewNode(value);
        node->rightNode = fillIntoNode(node->rightNode, ' ');
    }

    scope = loadCharacter();

    // ending 
    if (scope == '}') {
        return node;
    } else if (scope == ']') {
        // syntax error, I am not handling this just yet
        return node;
    }

    // opening
    if (scope == '{') {
        // recursion on the left node
        node->leftNode = createNewNode(NULL);
        node->leftNode = fillIntoNode(node->leftNode, '{');
    } else if (scope == '[') {
        // recursion on the right node
        node->rightNode = createNewNode(NULL);
        node->rightNode = fillIntoNode(node->rightNode, '[');
    }
    return node;
}

int main() {
// create root node, recursively add values to nodes
// determine if the scope is left or right
// check for closing brackets (closing scopes)
    struct Node *root = createNewNode(loadInteger());
    //printf(""%d"", root->value);
    root->leftNode = fillIntoNode(root, '{');
    root->rightNode = fillIntoNode(root, '[');
    printTreeInOrder(root);
    return 0;
}


// Validating the functionality of my createNewNode() function on this
//    struct Node *root = createNewNode(1);
//    root->leftNode = createNewNode(1);
//    root->rightNode = createNewNode(2);
//    root->leftNode->leftNode = createNewNode(3);
//    printTreeInOrder(root);
"
Tree parsing and in-order traversal,"#include <stdio.h>
#include <stdlib.h>

#define NULL ((void *)0)

struct Node {
    int value;
    struct Node *leftNode;
    struct Node *rightNode;
};

struct Node *createNewNode(int value) {
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    node->value = value;
    node->leftNode = NULL;
    node->rightNode = NULL;

    return node;
}

void printTreeInOrder(struct Node *node) {
    if (node == NULL)
        return;

    printTreeInOrder(node->leftNode);
    printf(""%d\n"", node->value);
    printTreeInOrder(node->rightNode);
}

char loadCharacter() {
    char charValue = getc(stdin);
    while (charValue == '\n' || charValue == ' ' || charValue == '\t') {
        charValue = getc(stdin);
    }
    return charValue;
}

struct Node *fillIntoNode(struct Node *node, char scope) {
    int oneMore = 0;
    if (scope != ' ') {
        oneMore = 1;
    }

    if (scope != '[' && scope != '{' && scope != ']' && scope != '}') {
        printf(""Invalid input"");
        exit(0);
    }

    // clever... yeah, for sure :D
    char numberString[1000];
    int counter = 0;
    char valueChar = loadCharacter();
    while (valueChar == '1' || valueChar == '2' || valueChar == '3' || valueChar == '4' || valueChar == '5' ||
           valueChar == '6' ||
           valueChar == '7' || valueChar == '8' || valueChar == '9' || valueChar == '0') {
        numberString[counter] = valueChar;
        counter = counter + 1;
        valueChar = loadCharacter();
    }

    char scopeInner = valueChar;

    // Gets the length of value (eg. 123 -> 3)
    int sizeOfParsedNumberString = 0;
    for (int i = 0; i < sizeof numberString / sizeof numberString[0]; ++i) {
        if (numberString[i] == '1' || numberString[i] == '2' || numberString[i] == '3' || numberString[i] == '4' ||
            numberString[i] == '5' || numberString[i] == '6' ||
            numberString[i] == '7' || numberString[i] == '8' || numberString[i] == '9' || numberString[i] == '0') {
            sizeOfParsedNumberString = sizeOfParsedNumberString + 1;
        } else {
            break;
        }
    }

    if (sizeOfParsedNumberString == 0) {
        printf(""Invalid input"");
        exit(0);
    }

    char *thisIsMandatoryButCommaItAddsStuffThatIsNotNumberHere;
    int value = strtol(numberString, &thisIsMandatoryButCommaItAddsStuffThatIsNotNumberHere, 10);

    // DESTROY THE ARRAY, OBLITERATE IT FROM THE FACE OF THE COMPILER (It doesn't work without this, I am not trying to be evil towards the non-pointer char array)
    // [and it doesn't even erase it, it just replaces all indexes with \000, which is some magical NULL value, or whatever]
    for (int i = 0; i < sizeof numberString / sizeof numberString[0]; ++i) {
        numberString[i] = '\000';
    }

    node = createNewNode(value);

    // inner scope -> opens another node
    if (scopeInner == '{') {
        node->leftNode = createNewNode(NULL);
        node->leftNode = fillIntoNode(node->leftNode, '{');
    } else if (scopeInner == '[') {
        node->rightNode = createNewNode(NULL);
        node->rightNode = fillIntoNode(node->rightNode, '[');
    }

    // inner scope -> closes current node 
    if (scopeInner != '{' && scopeInner != '[') {
        if (scope == '{' && scopeInner != '}') {
            printf(""Invalid input"");
            exit(0);
        } else if (scope == '[' && scopeInner != ']') {
            printf(""Invalid input"");
            exit(0);
        } else if (scope == '{' && scopeInner == '}' || scope == '[' && scopeInner == ']') {
            return node;
        }
    }


    // This part of the code checks for possible second child node from the current node
    scope = loadCharacter();

    // inner scope -> opens another node
    if (scope == '{') {
        node->leftNode = createNewNode(NULL);
        node->leftNode = fillIntoNode(node->leftNode, '{');
    } else if (scope == '[') {
        node->rightNode = createNewNode(NULL);
        node->rightNode = fillIntoNode(node->rightNode, '[');
    }

    // This part will need some more edge case handling, but basically,
    // If I pass a scope into fillIntoMagic, the logic makes it so it does not loadCharacter for the current node's scope
    // I could as well change it a bit, as there is no instance of me not passing in a scope, but,... yeah
    if (oneMore) {
        scope = loadCharacter();
    }
    return node;
}

struct Node *parseRoot(struct Node *root) {
    char scope = loadCharacter();
    if (scope == '{') {
        root->leftNode = fillIntoNode(root->leftNode, '{');
    } else if (scope == '[') {
        root->rightNode = fillIntoNode(root->rightNode, '[');
    }
    scope = loadCharacter();
    if (scope == '{') {
        root->leftNode = fillIntoNode(root->leftNode, '{');
    } else if (scope == '[') {
        root->rightNode = fillIntoNode(root->rightNode, '[');
    }
    return root;
}

int main() {
    int intValue;
    if (scanf(""%d"", &intValue) == EOF) {
        printf(""%s"", ""Invalid input"");
        return 0;
    }
    struct Node *root = createNewNode(intValue);
    root = parseRoot(root);
    printTreeInOrder(root);
    return 0;
}"
Tree parsing and in-order traversal,"#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *leftNode;
    struct Node *rightNode;
};

struct Node *createNewNode(int value) {
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    node->value = value;
    node->leftNode = NULL;
    node->rightNode = NULL;

    return node;
}

void printTreeInOrder(struct Node *node) {
    if (node == NULL)
        return;

    printTreeInOrder(node->leftNode);
    printf(""%d\n"", node->value);
    printTreeInOrder(node->rightNode);
}

char loadCharacter() {
    char charValue = getc(stdin);
    while (charValue == '\n' || charValue == ' ' || charValue == '\t') {
        charValue = getc(stdin);
    }
    return charValue;
}

struct Node *fillIntoNode(struct Node *node, char scope) {
    int oneMore = 0;
    if (scope != ' ') {
        oneMore = 1;
    }

    if (scope != '[' && scope != '{' && scope != ']' && scope != '}') {
        printf(""Invalid input"");
        exit(0);
    }

    // clever... yeah, for sure :D
    char numberString[1000];
    int counter = 0;
    char valueChar = loadCharacter();
    while (valueChar == '1' || valueChar == '2' || valueChar == '3' || valueChar == '4' || valueChar == '5' ||
           valueChar == '6' ||
           valueChar == '7' || valueChar == '8' || valueChar == '9' || valueChar == '0') {
        numberString[counter] = valueChar;
        counter = counter + 1;
        valueChar = loadCharacter();
    }

    char scopeInner = valueChar;

    // Gets the length of value (eg. 123 -> 3)
    int sizeOfParsedNumberString = 0;
    for (int i = 0; i < sizeof numberString / sizeof numberString[0]; ++i) {
        if (numberString[i] == '1' || numberString[i] == '2' || numberString[i] == '3' || numberString[i] == '4' ||
            numberString[i] == '5' || numberString[i] == '6' ||
            numberString[i] == '7' || numberString[i] == '8' || numberString[i] == '9' || numberString[i] == '0') {
            sizeOfParsedNumberString = sizeOfParsedNumberString + 1;
        } else {
            break;
        }
    }

    if (sizeOfParsedNumberString == 0) {
        printf(""Invalid input"");
        exit(0);
    }

    char *thisIsMandatoryButCommaItAddsStuffThatIsNotNumberHere;
    int value = strtol(numberString, &thisIsMandatoryButCommaItAddsStuffThatIsNotNumberHere, 10);

    // DESTROY THE ARRAY, OBLITERATE IT FROM THE FACE OF THE COMPILER (It doesn't work without this, I am not trying to be evil towards the non-pointer char array)
    // [and it doesn't even erase it, it just replaces all indexes with \000, which is some magical NULL value, or whatever]
    for (int i = 0; i < sizeof numberString / sizeof numberString[0]; ++i) {
        numberString[i] = '\000';
    }

    node = createNewNode(value);

    // inner scope -> opens another node
    if (scopeInner == '{') {
        node->leftNode = createNewNode(0);
        node->leftNode = fillIntoNode(node->leftNode, '{');
    } else if (scopeInner == '[') {
        node->rightNode = createNewNode(0);
        node->rightNode = fillIntoNode(node->rightNode, '[');
    }

    // inner scope -> closes current node 
    if (scopeInner != '{' && scopeInner != '[') {
        if (scope == '{' && scopeInner != '}') {
            printf(""Invalid input"");
            exit(0);
        } else if (scope == '[' && scopeInner != ']') {
            printf(""Invalid input"");
            exit(0);
        } else if (scope == '{' && scopeInner == '}' || scope == '[' && scopeInner == ']') {
            return node;
        }
    }


    // This part of the code checks for possible second child node from the current node
    scope = loadCharacter();

    // inner scope -> opens another node
    if (scope == '{') {
        node->leftNode = createNewNode(0);
        node->leftNode = fillIntoNode(node->leftNode, '{');
    } else if (scope == '[') {
        node->rightNode = createNewNode(0);
        node->rightNode = fillIntoNode(node->rightNode, '[');
    }

    // This part will need some more edge case handling, but basically,
    // If I pass a scope into fillIntoMagic, the logic makes it so it does not loadCharacter for the current node's scope
    // I could as well change it a bit, as there is no instance of me not passing in a scope, but,... yeah
    if (oneMore) {
        scopeInner = loadCharacter();
    }
//        if (scope == '{' && scopeInner != '}') {
//            printf(""Invalid input"");
//            exit(0);
//        } else if (scope == '[' && scopeInner != ']') {
//            printf(""Invalid input"");
//            exit(0);
//        } else if (scope == '{' && scopeInner == '}' || scope == '[' && scopeInner == ']') {
//            return node;
//        }
    return node;
}

struct Node *parseRoot(struct Node *root) {
    char scope = loadCharacter();
    if (scope == '{') {
        root->leftNode = fillIntoNode(root->leftNode, '{');
    } else if (scope == '[') {
        root->rightNode = fillIntoNode(root->rightNode, '[');
    }
    scope = loadCharacter();
    if (scope == '{') {
        root->leftNode = fillIntoNode(root->leftNode, '{');
    } else if (scope == '[') {
        root->rightNode = fillIntoNode(root->rightNode, '[');
    }
    return root;
}

int main() {
    int intValue;
    if (scanf(""%d"", &intValue) == EOF) {
        printf(""%s"", ""Invalid input"");
        return 0;
    }
    struct Node *root = createNewNode(intValue);
    root = parseRoot(root);
    printTreeInOrder(root);
    return 0;
}"
Tree parsing and in-order traversal,"#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *leftNode;
    struct Node *rightNode;
};

struct Node *createNewNode(int value) {
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    node->value = value;
    node->leftNode = NULL;
    node->rightNode = NULL;

    return node;
}

void printTreeInOrder(struct Node *node) {
    if (node == NULL)
        return;

    printTreeInOrder(node->leftNode);
    printf(""%d\n"", node->value);
    printTreeInOrder(node->rightNode);
}

char loadCharacter() {
    char charValue = getc(stdin);
    while (charValue == '\n' || charValue == ' ' || charValue == '\t') {
        charValue = getc(stdin);
    }
    return charValue;
}

struct Node *fillIntoNode(struct Node *node, char scope) {
    int oneMore = 0;
    if (scope != ' ') {
        oneMore = 1;
    }

    if (scope != '[' && scope != '{' && scope != ']' && scope != '}') {
        printf(""Invalid input"");
        exit(0);
    }

    // clever... yeah, for sure :D
    char numberString[1000];
    int counter = 0;
    char valueChar = loadCharacter();
    while (valueChar == '1' || valueChar == '2' || valueChar == '3' || valueChar == '4' || valueChar == '5' ||
           valueChar == '6' ||
           valueChar == '7' || valueChar == '8' || valueChar == '9' || valueChar == '0') {
        numberString[counter] = valueChar;
        counter = counter + 1;
        valueChar = loadCharacter();
    }

    char scopeInner = valueChar;

    // Gets the length of value (eg. 123 -> 3)
    int sizeOfParsedNumberString = 0;
    for (int i = 0; i < sizeof numberString / sizeof numberString[0]; ++i) {
        if (numberString[i] == '1' || numberString[i] == '2' || numberString[i] == '3' || numberString[i] == '4' ||
            numberString[i] == '5' || numberString[i] == '6' ||
            numberString[i] == '7' || numberString[i] == '8' || numberString[i] == '9' || numberString[i] == '0') {
            sizeOfParsedNumberString = sizeOfParsedNumberString + 1;
        } else {
            break;
        }
    }

    if (sizeOfParsedNumberString == 0) {
        printf(""Invalid input"");
        exit(0);
    }

    char *thisIsMandatoryButCommaItAddsStuffThatIsNotNumberHere;
    int value = strtol(numberString, &thisIsMandatoryButCommaItAddsStuffThatIsNotNumberHere, 10);

    // DESTROY THE ARRAY, OBLITERATE IT FROM THE FACE OF THE COMPILER (It doesn't work without this, I am not trying to be evil towards the non-pointer char array)
    // [and it doesn't even erase it, it just replaces all indexes with \000, which is some magical NULL value, or whatever]
    for (int i = 0; i < sizeof numberString / sizeof numberString[0]; ++i) {
        numberString[i] = '\000';
    }

    node = createNewNode(value);

    // inner scope -> opens another node
    if (scopeInner == '{') {
        node->leftNode = createNewNode(0);
        node->leftNode = fillIntoNode(node->leftNode, '{');
    } else if (scopeInner == '[') {
        node->rightNode = createNewNode(0);
        node->rightNode = fillIntoNode(node->rightNode, '[');
    }

    // inner scope -> closes current node 
    if (scopeInner != '{' && scopeInner != '[') {
        if (scope == '{' && scopeInner != '}') {
            printf(""Invalid input"");
            exit(0);
        } else if (scope == '[' && scopeInner != ']') {
            printf(""Invalid input"");
            exit(0);
        } else if (scope == '{' && scopeInner == '}' || scope == '[' && scopeInner == ']') {
            return node;
        }
    }


    // This part of the code checks for possible second child node from the current node
    scope = loadCharacter();

    // inner scope -> opens another node
    if (scope == '{') {
        node->leftNode = createNewNode(0);
        node->leftNode = fillIntoNode(node->leftNode, '{');
    } else if (scope == '[') {
        node->rightNode = createNewNode(0);
        node->rightNode = fillIntoNode(node->rightNode, '[');
    }

    // This part will need some more edge case handling, but basically,
    // If I pass a scope into fillIntoMagic, the logic makes it so it does not loadCharacter for the current node's scope
    // I could as well change it a bit, as there is no instance of me not passing in a scope, but,... yeah
    if (oneMore) {
        scopeInner = loadCharacter();
    }
    return node;
}

struct Node *parseRoot(struct Node *root) {
    char scope = loadCharacter();
    if (scope == '{') {
        root->leftNode = fillIntoNode(root->leftNode, '{');
    } else if (scope == '[') {
        root->rightNode = fillIntoNode(root->rightNode, '[');
    } else {
        printf(""Invalid input"");
        exit(0);
    }
    scope = loadCharacter();
    if (scope == '{') {
        root->leftNode = fillIntoNode(root->leftNode, '{');
    } else if (scope == '[') {
        root->rightNode = fillIntoNode(root->rightNode, '[');
    } else {
        printf(""Invalid input"");
        exit(0);
    }
    return root;
}

int main() {
    int intValue;
    if (scanf(""%d"", &intValue) == EOF) {
        printf(""%s"", ""Invalid input"");
        return 0;
    }
    struct Node *root = createNewNode(intValue);
    root = parseRoot(root);
    printTreeInOrder(root);
    return 0;
}"
Tree parsing and in-order traversal,"#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *leftNode;
    struct Node *rightNode;
};

struct valueLeftRight {
    int lv;
    int rv;
} scopeKeeper;

struct Node *createNewNode(int value) {
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    node->value = value;
    node->leftNode = NULL;
    node->rightNode = NULL;

    return node;
}

void printTreeInOrder(struct Node *node) {
    if (node == NULL)
        return;

    printTreeInOrder(node->leftNode);
    printf(""%d\n"", node->value);
    printTreeInOrder(node->rightNode);
}

char loadCharacter() {
    char charValue = getc(stdin);
    while (charValue == '\n' || charValue == ' ' || charValue == '\t') {
        charValue = getc(stdin);
    }
    return charValue;
}

struct Node *fillIntoNode(struct Node *node, char scope) {
    int oneMore = 0;
    if (scope != ' ') {
        oneMore = 1;
    }

    if (scope != '[' && scope != '{' && scope != ']' && scope != '}') {
        printf(""Invalid input"");
        exit(0);
    }

    // clever... yeah, for sure :D
    char numberString[1000];
    int counter = 0;
    char valueChar = loadCharacter();
    while (valueChar == '1' || valueChar == '2' || valueChar == '3' || valueChar == '4' || valueChar == '5' ||
           valueChar == '6' ||
           valueChar == '7' || valueChar == '8' || valueChar == '9' || valueChar == '0') {
        numberString[counter] = valueChar;
        counter = counter + 1;
        valueChar = loadCharacter();
    }

    char scopeInner = valueChar;

    // Gets the length of value (eg. 123 -> 3)
    int sizeOfParsedNumberString = 0;
    for (int i = 0; i < sizeof numberString / sizeof numberString[0]; ++i) {
        if (numberString[i] == '1' || numberString[i] == '2' || numberString[i] == '3' || numberString[i] == '4' ||
            numberString[i] == '5' || numberString[i] == '6' ||
            numberString[i] == '7' || numberString[i] == '8' || numberString[i] == '9' || numberString[i] == '0') {
            sizeOfParsedNumberString = sizeOfParsedNumberString + 1;
        } else {
            break;
        }
    }

    if (sizeOfParsedNumberString == 0) {
        printf(""Invalid input"");
        exit(0);
    }

    char *thisIsMandatoryButCommaItAddsStuffThatIsNotNumberHere;
    int value = strtol(numberString, &thisIsMandatoryButCommaItAddsStuffThatIsNotNumberHere, 10);

    // DESTROY THE ARRAY, OBLITERATE IT FROM THE FACE OF THE COMPILER (It doesn't work without this, I am not trying to be evil towards the non-pointer char array)
    // [and it doesn't even erase it, it just replaces all indexes with \000, which is some magical NULL value, or whatever]
    for (int i = 0; i < sizeof numberString / sizeof numberString[0]; ++i) {
        numberString[i] = '\000';
    }

    node = createNewNode(value);

    // inner scope -> opens another node
    if (scopeInner == '{') {
        scopeKeeper.lv = scopeKeeper.lv + 1;
        node->leftNode = createNewNode(0);
        node->leftNode = fillIntoNode(node->leftNode, '{');
    } else if (scopeInner == '[') {
        scopeKeeper.rv = scopeKeeper.rv + 1;
        node->rightNode = createNewNode(0);
        node->rightNode = fillIntoNode(node->rightNode, '[');
    }

    // inner scope -> closes current node 
    if (scopeInner != '{' && scopeInner != '[') {
        if (scope == '{' && scopeInner != '}') {
            printf(""Invalid input"");
            exit(0);
        } else if (scope == '[' && scopeInner != ']') {
            printf(""Invalid input"");
            exit(0);
        } else if (scope == '{' && scopeInner == '}') {
            scopeKeeper.lv = scopeKeeper.lv - 1;
            return node;
        } else if (scope == '[' && scopeInner == ']') {
            scopeKeeper.rv = scopeKeeper.rv - 1;
            return node;
        }
    }

    // This part of the code checks for possible second child node from the current node
    scopeInner = loadCharacter();

    // inner scope -> opens another node
    if (scopeInner == '{') {
        scopeKeeper.lv = scopeKeeper.lv + 1;
        node->leftNode = createNewNode(0);
        node->leftNode = fillIntoNode(node->leftNode, '{');
    } else if (scopeInner == '[') {
        scopeKeeper.rv = scopeKeeper.rv + 1;
        node->rightNode = createNewNode(0);
        node->rightNode = fillIntoNode(node->rightNode, '[');
    }

    // inner scope -> closes current node 
    if (scopeInner != '{' && scopeInner != '[') {
        if (scope == '{' && scopeInner != '}') {
            printf(""Invalid input"");
            exit(0);
        } else if (scope == '[' && scopeInner != ']') {
            printf(""Invalid input"");
            exit(0);
        } else if (scope == '{' && scopeInner == '}') {
            scopeKeeper.lv = scopeKeeper.lv - 1;
            return node;
        } else if (scope == '[' && scopeInner == ']') {
            scopeKeeper.rv = scopeKeeper.rv - 1;
            return node;
        }
    }

    // This part will need some more edge case handling, but basically,
    // If I pass a scope into fillIntoMagic, the logic makes it so it does not loadCharacter for the current node's scope
    // I could as well change it a bit, as there is no instance of me not passing in a scope, but,... yeah
    if (oneMore) {
        scopeInner = loadCharacter();
        if (scopeInner == '}') {
            scopeKeeper.lv = scopeKeeper.lv - 1;
        } else if (scopeInner == ']') {
            scopeKeeper.rv = scopeKeeper.rv - 1;
        }
    }
    return node;
}

struct Node *parseRoot(struct Node *root) {
    char scope = loadCharacter();
    if (scope == '{') {
        scopeKeeper.lv = scopeKeeper.lv + 1;
        root->leftNode = fillIntoNode(root->leftNode, '{');
    } else if (scope == '[') {
        scopeKeeper.rv = scopeKeeper.rv + 1;
        root->rightNode = fillIntoNode(root->rightNode, '[');
    }
    scope = loadCharacter();
    if (scope == '{') {
        scopeKeeper.lv = scopeKeeper.lv + 1;
        root->leftNode = fillIntoNode(root->leftNode, '{');
    } else if (scope == '[') {
        scopeKeeper.rv = scopeKeeper.rv + 1;
        root->rightNode = fillIntoNode(root->rightNode, '[');
    }
    return root;
}

int main() {
    int intValue;
    if (scanf(""%d"", &intValue) != EOF) {
        struct Node *root = createNewNode(intValue);
        root = parseRoot(root);
        if (scopeKeeper.lv != 0 || scopeKeeper.rv != 0) {
            printf(""Invalid input"");
            exit(0);
        }
        printTreeInOrder(root);
    }
    return 0;
}"
Tree parsing and in-order traversal,"#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *leftNode;
    struct Node *rightNode;
};

struct valueLeftRight {
    int lv;
    int rv;
} scopeKeeper;

struct Node *createNewNode(int value) {
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    node->value = value;
    node->leftNode = NULL;
    node->rightNode = NULL;

    return node;
}

void printTreeInOrder(struct Node *node) {
    if (node == NULL)
        return;

    printTreeInOrder(node->leftNode);
    printf(""%d\n"", node->value);
    printTreeInOrder(node->rightNode);
}

char loadCharacter() {
    char charValue = getc(stdin);
    while (charValue == '\n' || charValue == ' ' || charValue == '\t') {
        charValue = getc(stdin);
    }
    return charValue;
}

struct Node *fillIntoNode(struct Node *node, char scope) {
    int oneMore = 0;
    if (scope != ' ') {
        oneMore = 1;
    }

    if (scope != '[' && scope != '{' && scope != ']' && scope != '}') {
        printf(""Invalid input"");
        exit(0);
    }

    // clever... yeah, for sure :D
    char numberString[1000];
    int counter = 0;
    char valueChar = loadCharacter();
    while (valueChar == '1' || valueChar == '2' || valueChar == '3' || valueChar == '4' || valueChar == '5' ||
           valueChar == '6' ||
           valueChar == '7' || valueChar == '8' || valueChar == '9' || valueChar == '0') {
        numberString[counter] = valueChar;
        counter = counter + 1;
        valueChar = loadCharacter();
    }

    char scopeInner = valueChar;

    // Gets the length of value (eg. 123 -> 3)
    int sizeOfParsedNumberString = 0;
    for (int i = 0; i < sizeof numberString / sizeof numberString[0]; ++i) {
        if (numberString[i] == '1' || numberString[i] == '2' || numberString[i] == '3' || numberString[i] == '4' ||
            numberString[i] == '5' || numberString[i] == '6' ||
            numberString[i] == '7' || numberString[i] == '8' || numberString[i] == '9' || numberString[i] == '0') {
            sizeOfParsedNumberString = sizeOfParsedNumberString + 1;
        } else {
            break;
        }
    }

    if (sizeOfParsedNumberString == 0) {
        printf(""Invalid input"");
        exit(0);
    }

    char *thisIsMandatoryButCommaItAddsStuffThatIsNotNumberHere;
    int value = strtol(numberString, &thisIsMandatoryButCommaItAddsStuffThatIsNotNumberHere, 10);

    // DESTROY THE ARRAY, OBLITERATE IT FROM THE FACE OF THE COMPILER (It doesn't work without this, I am not trying to be evil towards the non-pointer char array)
    // [and it doesn't even erase it, it just replaces all indexes with \000, which is some magical NULL value, or whatever]
    for (int i = 0; i < sizeof numberString / sizeof numberString[0]; ++i) {
        numberString[i] = '\000';
    }

    node = createNewNode(value);

    // inner scope -> opens another node
    if (scopeInner == '{') {
        scopeKeeper.lv = scopeKeeper.lv + 1;
        node->leftNode = createNewNode(0);
        node->leftNode = fillIntoNode(node->leftNode, '{');
    } else if (scopeInner == '[') {
        scopeKeeper.rv = scopeKeeper.rv + 1;
        node->rightNode = createNewNode(0);
        node->rightNode = fillIntoNode(node->rightNode, '[');
    }

    // inner scope -> closes current node 
    if (scopeInner != '{' && scopeInner != '[') {
        if (scope == '{' && scopeInner != '}') {
            printf(""Invalid input"");
            exit(0);
        } else if (scope == '[' && scopeInner != ']') {
            printf(""Invalid input"");
            exit(0);
        } else if (scope == '{' && scopeInner == '}') {
            scopeKeeper.lv = scopeKeeper.lv - 1;
            return node;
        } else if (scope == '[' && scopeInner == ']') {
            scopeKeeper.rv = scopeKeeper.rv - 1;
            return node;
        }
    }

    // This part of the code checks for possible second child node from the current node
    scopeInner = loadCharacter();

    // inner scope -> opens another node
    if (scopeInner == '{') {
        scopeKeeper.lv = scopeKeeper.lv + 1;
        node->leftNode = createNewNode(0);
        node->leftNode = fillIntoNode(node->leftNode, '{');
    } else if (scopeInner == '[') {
        scopeKeeper.rv = scopeKeeper.rv + 1;
        node->rightNode = createNewNode(0);
        node->rightNode = fillIntoNode(node->rightNode, '[');
    }

    // inner scope -> closes current node 
    if (scopeInner != '{' && scopeInner != '[') {
        if (scope == '{' && scopeInner != '}') {
            printf(""Invalid input"");
            exit(0);
        } else if (scope == '[' && scopeInner != ']') {
            printf(""Invalid input"");
            exit(0);
        } else if (scope == '{' && scopeInner == '}') {
            scopeKeeper.lv = scopeKeeper.lv - 1;
            return node;
        } else if (scope == '[' && scopeInner == ']') {
            scopeKeeper.rv = scopeKeeper.rv - 1;
            return node;
        }
    }

    // This part will need some more edge case handling, but basically,
    // If I pass a scope into fillIntoMagic, the logic makes it so it does not loadCharacter for the current node's scope
    // I could as well change it a bit, as there is no instance of me not passing in a scope, but,... yeah
    if (oneMore) {
        scopeInner = loadCharacter();
        if (scopeInner == '}') {
            scopeKeeper.lv = scopeKeeper.lv - 1;
        } else if (scopeInner == ']') {
            scopeKeeper.rv = scopeKeeper.rv - 1;
        }
    }
    return node;
}

struct Node *parseRoot(struct Node *root, char firstScope) {
    if (firstScope == '{') {
        scopeKeeper.lv = scopeKeeper.lv + 1;
        root->leftNode = fillIntoNode(root->leftNode, '{');
    } else if (firstScope == '[') {
        scopeKeeper.rv = scopeKeeper.rv + 1;
        root->rightNode = fillIntoNode(root->rightNode, '[');
    }
    char scope = loadCharacter();
    if (scope == '{') {
        scopeKeeper.lv = scopeKeeper.lv + 1;
        root->leftNode = fillIntoNode(root->leftNode, '{');
    } else if (scope == '[') {
        scopeKeeper.rv = scopeKeeper.rv + 1;
        root->rightNode = fillIntoNode(root->rightNode, '[');
    }
    return root;
}

int main() {
    // So, when the root is non existant, but the rest is (it's got some nodes), the program will continue even though it should error out.
    // clever... yeah, for sure :D
    char buffer[1000];
    int counter = 0;
    char valueChar = loadCharacter();
    if (valueChar != '1' && valueChar != '2' && valueChar != '3' && valueChar != '4' && valueChar != '5' &&
        valueChar != '6' &&
        valueChar != '7' && valueChar != '8' && valueChar != '9' && valueChar != '0') {
        buffer[0] = valueChar;
    }
    while (valueChar == '1' || valueChar == '2' || valueChar == '3' || valueChar == '4' || valueChar == '5' ||
           valueChar == '6' ||
           valueChar == '7' || valueChar == '8' || valueChar == '9' || valueChar == '0') {
        buffer[counter] = valueChar;
        counter = counter + 1;
        valueChar = loadCharacter();
    }
    
    char scopeInner = valueChar;

    // Gets the length of value (eg. 123 -> 3)
    int sizeOfParsedNumberString = 0;
    for (int i = 0; i < sizeof buffer / sizeof buffer[0]; ++i) {
        if (buffer[i] == '1' || buffer[i] == '2' || buffer[i] == '3' || buffer[i] == '4' ||
            buffer[i] == '5' || buffer[i] == '6' ||
            buffer[i] == '7' || buffer[i] == '8' || buffer[i] == '9' || buffer[i] == '0') {
            sizeOfParsedNumberString = sizeOfParsedNumberString + 1;
        } else {
            break;
        }
    }

    int value;
    if (sizeOfParsedNumberString == 0) {
        if (buffer[0] == '{' || buffer[0] == '[' || buffer[0] == '}' || buffer[0] == ']') {
            printf(""Invalid input"");
            exit(0);
        }
        exit(0);
    } else {
        //char *thisIsMandatoryButCommaItAddsStuffThatIsNotNumberHere;
        //value = strtol(buffer, &thisIsMandatoryButCommaItAddsStuffThatIsNotNumberHere, 10);
        value = atoi(buffer);
    }

   // char *thisIsMandatoryButCommaItAddsStuffThatIsNotNumberHere;
   // int value = strtol(buffer, &thisIsMandatoryButCommaItAddsStuffThatIsNotNumberHere, 10);
    
    if (sizeOfParsedNumberString >= 1) {
        struct Node *root = createNewNode(value);
        root = parseRoot(root, scopeInner);
        if (scopeKeeper.lv != 0 || scopeKeeper.rv != 0) {
            printf(""Invalid input"");
            exit(0);
        }
        printTreeInOrder(root);
    }
    return 0;
}"
Tree parsing and in-order traversal,"#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *leftNode;
    struct Node *rightNode;
};

struct valueLeftRight {
    int lv;
    int rv;
} scopeKeeper;

struct Node *createNewNode(int value) {
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    node->value = value;
    node->leftNode = NULL;
    node->rightNode = NULL;

    return node;
}

void printTreeInOrder(struct Node *node) {
    if (node == NULL)
        return;

    printTreeInOrder(node->leftNode);
    printf(""%d\n"", node->value);
    printTreeInOrder(node->rightNode);
}

char loadCharacter() {
    char charValue = getc(stdin);
    while (charValue == '\n' || charValue == ' ' || charValue == '\t') {
        charValue = getc(stdin);
    }
    return charValue;
}

struct Node *fillIntoNode(struct Node *node, char scope) {
    int oneMore = 0;
    if (scope != ' ') {
        oneMore = 1;
    }

    if (scope != '[' && scope != '{' && scope != ']' && scope != '}') {
        printf(""Invalid input"");
        exit(0);
    }

    // clever... yeah, for sure :D
    char numberString[1000];
    int counter = 0;
    char valueChar = loadCharacter();
    while (valueChar == '1' || valueChar == '2' || valueChar == '3' || valueChar == '4' || valueChar == '5' ||
           valueChar == '6' ||
           valueChar == '7' || valueChar == '8' || valueChar == '9' || valueChar == '0') {
        numberString[counter] = valueChar;
        counter = counter + 1;
        valueChar = loadCharacter();
    }

    char scopeInner = valueChar;

    // Gets the length of value (eg. 123 -> 3)
    int sizeOfParsedNumberString = 0;
    for (int i = 0; i < sizeof numberString / sizeof numberString[0]; ++i) {
        if (numberString[i] == '1' || numberString[i] == '2' || numberString[i] == '3' || numberString[i] == '4' ||
            numberString[i] == '5' || numberString[i] == '6' ||
            numberString[i] == '7' || numberString[i] == '8' || numberString[i] == '9' || numberString[i] == '0') {
            sizeOfParsedNumberString = sizeOfParsedNumberString + 1;
        } else {
            break;
        }
    }

    if (sizeOfParsedNumberString == 0) {
        printf(""Invalid input"");
        exit(0);
    }

    char *thisIsMandatoryButCommaItAddsStuffThatIsNotNumberHere;
    int value = strtol(numberString, &thisIsMandatoryButCommaItAddsStuffThatIsNotNumberHere, 10);

    // DESTROY THE ARRAY, OBLITERATE IT FROM THE FACE OF THE COMPILER (It doesn't work without this, I am not trying to be evil towards the non-pointer char array)
    // [and it doesn't even erase it, it just replaces all indexes with \000, which is some magical NULL value, or whatever]
    for (int i = 0; i < sizeof numberString / sizeof numberString[0]; ++i) {
        numberString[i] = '\000';
    }

    node = createNewNode(value);

    // inner scope -> opens another node
    if (scopeInner == '{') {
        scopeKeeper.lv = scopeKeeper.lv + 1;
        node->leftNode = createNewNode(0);
        node->leftNode = fillIntoNode(node->leftNode, '{');
    } else if (scopeInner == '[') {
        scopeKeeper.rv = scopeKeeper.rv + 1;
        node->rightNode = createNewNode(0);
        node->rightNode = fillIntoNode(node->rightNode, '[');
    }

    // inner scope -> closes current node 
    if (scopeInner != '{' && scopeInner != '[') {
        if (scope == '{' && scopeInner != '}') {
            printf(""Invalid input"");
            exit(0);
        } else if (scope == '[' && scopeInner != ']') {
            printf(""Invalid input"");
            exit(0);
        } else if (scope == '{' && scopeInner == '}') {
            scopeKeeper.lv = scopeKeeper.lv - 1;
            return node;
        } else if (scope == '[' && scopeInner == ']') {
            scopeKeeper.rv = scopeKeeper.rv - 1;
            return node;
        }
    }

    // This part of the code checks for possible second child node from the current node
    char scopeInner1 = loadCharacter();
    
    if (scopeInner == '{' && scopeInner1 == '{' || scopeInner == '[' && scopeInner1 == '[') {
        printf(""Invalid input"");
        exit(0);
    }
    
    // inner scope -> opens another node
    if (scopeInner1 == '{') {
        scopeKeeper.lv = scopeKeeper.lv + 1;
        node->leftNode = createNewNode(0);
        node->leftNode = fillIntoNode(node->leftNode, '{');
    } else if (scopeInner1 == '[') {
        scopeKeeper.rv = scopeKeeper.rv + 1;
        node->rightNode = createNewNode(0);
        node->rightNode = fillIntoNode(node->rightNode, '[');
    }

    // inner scope -> closes current node 
    if (scopeInner1 != '{' && scopeInner1 != '[') {
        if (scope == '{' && scopeInner1 != '}') {
            printf(""Invalid input"");
            exit(0);
        } else if (scope == '[' && scopeInner1 != ']') {
            printf(""Invalid input"");
            exit(0);
        } else if (scope == '{' && scopeInner1 == '}') {
            scopeKeeper.lv = scopeKeeper.lv - 1;
            return node;
        } else if (scope == '[' && scopeInner1 == ']') {
            scopeKeeper.rv = scopeKeeper.rv - 1;
            return node;
        }
    }

    // This part will need some more edge case handling, but basically,
    // If I pass a scope into fillIntoMagic, the logic makes it so it does not loadCharacter for the current node's scope
    // I could as well change it a bit, as there is no instance of me not passing in a scope, but,... yeah
    if (oneMore) {
        scopeInner = loadCharacter();
        if (scopeInner == '}') {
            scopeKeeper.lv = scopeKeeper.lv - 1;
        } else if (scopeInner == ']') {
            scopeKeeper.rv = scopeKeeper.rv - 1;
        }
    }
    return node;
}

struct Node *parseRoot(struct Node *root, char firstScope) {
    if (firstScope == '{') {
        scopeKeeper.lv = scopeKeeper.lv + 1;
        root->leftNode = fillIntoNode(root->leftNode, '{');
    } else if (firstScope == '[') {
        scopeKeeper.rv = scopeKeeper.rv + 1;
        root->rightNode = fillIntoNode(root->rightNode, '[');
    }
    char scope = loadCharacter();
    
    if (firstScope == '{' && scope == '{') {
        printf(""Invalid input"");
        exit(0);
    } else if (firstScope == '[' && scope == '[') {
        printf(""Invalid input"");
        exit(0);
    }
    if (scope == '{') {
        scopeKeeper.lv = scopeKeeper.lv + 1;
        root->leftNode = fillIntoNode(root->leftNode, '{');
    } else if (scope == '[') {
        scopeKeeper.rv = scopeKeeper.rv + 1;
        root->rightNode = fillIntoNode(root->rightNode, '[');
    }
    return root;
}

int main() {
    // So, when the root is non existant, but the rest is (it's got some nodes), the program will continue even though it should error out.
    // clever... yeah, for sure :D
    char buffer[1000];
    int counter = 0;
    char valueChar = loadCharacter();
    if (valueChar != '1' && valueChar != '2' && valueChar != '3' && valueChar != '4' && valueChar != '5' &&
        valueChar != '6' &&
        valueChar != '7' && valueChar != '8' && valueChar != '9' && valueChar != '0') {
        buffer[0] = valueChar;
    }
    while (valueChar == '1' || valueChar == '2' || valueChar == '3' || valueChar == '4' || valueChar == '5' ||
           valueChar == '6' ||
           valueChar == '7' || valueChar == '8' || valueChar == '9' || valueChar == '0') {
        buffer[counter] = valueChar;
        counter = counter + 1;
        valueChar = loadCharacter();
    }
    
    char scopeInner = valueChar;

    // Gets the length of value (eg. 123 -> 3)
    int sizeOfParsedNumberString = 0;
    for (int i = 0; i < sizeof buffer / sizeof buffer[0]; ++i) {
        if (buffer[i] == '1' || buffer[i] == '2' || buffer[i] == '3' || buffer[i] == '4' ||
            buffer[i] == '5' || buffer[i] == '6' ||
            buffer[i] == '7' || buffer[i] == '8' || buffer[i] == '9' || buffer[i] == '0') {
            sizeOfParsedNumberString = sizeOfParsedNumberString + 1;
        } else {
            break;
        }
    }

    int value;
    if (sizeOfParsedNumberString == 0) {
        if (buffer[0] == '{' || buffer[0] == '[' || buffer[0] == '}' || buffer[0] == ']') {
            printf(""Invalid input"");
            exit(0);
        }
        exit(0);
    } else {
        value = atoi(buffer);
    }

    if (sizeOfParsedNumberString >= 1) {
        struct Node *root = createNewNode(value);
        root = parseRoot(root, scopeInner);
        if (scopeKeeper.lv != 0 || scopeKeeper.rv != 0) {
            printf(""Invalid input"");
            exit(0);
        }
        printTreeInOrder(root);
    }
    return 0;
}"
Tree parsing and pre-order traversal,"#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *leftNode;
    struct Node *rightNode;
};

struct valueLeftRight {
    int lv;
    int rv;
} scopeKeeper;

struct Node *createNewNode(int value) {
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    node->value = value;
    node->leftNode = NULL;
    node->rightNode = NULL;

    return node;
}

void printTreeInOrder(struct Node *node) {
    if (node == NULL)
        return;

    printf(""%d\n"", node->value);
    printTreeInOrder(node->leftNode);
    printTreeInOrder(node->rightNode);
}

char loadCharacter() {
    char charValue = getc(stdin);
    while (charValue == '\n' || charValue == ' ' || charValue == '\t') {
        charValue = getc(stdin);
    }
    return charValue;
}

struct Node *fillIntoNode(struct Node *node, char scope) {
    int oneMore = 0;
    if (scope != ' ') {
        oneMore = 1;
    }

    if (scope != '[' && scope != '{' && scope != ']' && scope != '}') {
        printf(""Invalid input"");
        exit(0);
    }

    // clever... yeah, for sure :D
    char numberString[1000];
    int counter = 0;
    char valueChar = loadCharacter();
    while (valueChar == '1' || valueChar == '2' || valueChar == '3' || valueChar == '4' || valueChar == '5' ||
           valueChar == '6' ||
           valueChar == '7' || valueChar == '8' || valueChar == '9' || valueChar == '0') {
        numberString[counter] = valueChar;
        counter = counter + 1;
        valueChar = loadCharacter();
    }

    char scopeInner = valueChar;

    // Gets the length of value (eg. 123 -> 3)
    int sizeOfParsedNumberString = 0;
    for (int i = 0; i < sizeof numberString / sizeof numberString[0]; ++i) {
        if (numberString[i] == '1' || numberString[i] == '2' || numberString[i] == '3' || numberString[i] == '4' ||
            numberString[i] == '5' || numberString[i] == '6' ||
            numberString[i] == '7' || numberString[i] == '8' || numberString[i] == '9' || numberString[i] == '0') {
            sizeOfParsedNumberString = sizeOfParsedNumberString + 1;
        } else {
            break;
        }
    }

    if (sizeOfParsedNumberString == 0) {
        printf(""Invalid input"");
        exit(0);
    }

    char *thisIsMandatoryButCommaItAddsStuffThatIsNotNumberHere;
    int value = strtol(numberString, &thisIsMandatoryButCommaItAddsStuffThatIsNotNumberHere, 10);

    // DESTROY THE ARRAY, OBLITERATE IT FROM THE FACE OF THE COMPILER (It doesn't work without this, I am not trying to be evil towards the non-pointer char array)
    // [and it doesn't even erase it, it just replaces all indexes with \000, which is some magical NULL value, or whatever]
    for (int i = 0; i < sizeof numberString / sizeof numberString[0]; ++i) {
        numberString[i] = '\000';
    }

    node = createNewNode(value);

    // inner scope -> opens another node
    if (scopeInner == '{') {
        scopeKeeper.lv = scopeKeeper.lv + 1;
        node->leftNode = createNewNode(0);
        node->leftNode = fillIntoNode(node->leftNode, '{');
    } else if (scopeInner == '[') {
        scopeKeeper.rv = scopeKeeper.rv + 1;
        node->rightNode = createNewNode(0);
        node->rightNode = fillIntoNode(node->rightNode, '[');
    }

    // inner scope -> closes current node 
    if (scopeInner != '{' && scopeInner != '[') {
        if (scope == '{' && scopeInner != '}') {
            printf(""Invalid input"");
            exit(0);
        } else if (scope == '[' && scopeInner != ']') {
            printf(""Invalid input"");
            exit(0);
        } else if (scope == '{' && scopeInner == '}') {
            scopeKeeper.lv = scopeKeeper.lv - 1;
            return node;
        } else if (scope == '[' && scopeInner == ']') {
            scopeKeeper.rv = scopeKeeper.rv - 1;
            return node;
        }
    }

    // This part of the code checks for possible second child node from the current node
    char scopeInner1 = loadCharacter();
    
    if (scopeInner == '{' && scopeInner1 == '{' || scopeInner == '[' && scopeInner1 == '[') {
        printf(""Invalid input"");
        exit(0);
    }
    
    // inner scope -> opens another node
    if (scopeInner1 == '{') {
        scopeKeeper.lv = scopeKeeper.lv + 1;
        node->leftNode = createNewNode(0);
        node->leftNode = fillIntoNode(node->leftNode, '{');
    } else if (scopeInner1 == '[') {
        scopeKeeper.rv = scopeKeeper.rv + 1;
        node->rightNode = createNewNode(0);
        node->rightNode = fillIntoNode(node->rightNode, '[');
    }

    // inner scope -> closes current node 
    if (scopeInner1 != '{' && scopeInner1 != '[') {
        if (scope == '{' && scopeInner1 != '}') {
            printf(""Invalid input"");
            exit(0);
        } else if (scope == '[' && scopeInner1 != ']') {
            printf(""Invalid input"");
            exit(0);
        } else if (scope == '{' && scopeInner1 == '}') {
            scopeKeeper.lv = scopeKeeper.lv - 1;
            return node;
        } else if (scope == '[' && scopeInner1 == ']') {
            scopeKeeper.rv = scopeKeeper.rv - 1;
            return node;
        }
    }

    // This part will need some more edge case handling, but basically,
    // If I pass a scope into fillIntoMagic, the logic makes it so it does not loadCharacter for the current node's scope
    // I could as well change it a bit, as there is no instance of me not passing in a scope, but,... yeah
    if (oneMore) {
        scopeInner = loadCharacter();
        if (scopeInner == '}') {
            scopeKeeper.lv = scopeKeeper.lv - 1;
        } else if (scopeInner == ']') {
            scopeKeeper.rv = scopeKeeper.rv - 1;
        }
    }
    return node;
}

struct Node *parseRoot(struct Node *root, char firstScope) {
    if (firstScope == '{') {
        scopeKeeper.lv = scopeKeeper.lv + 1;
        root->leftNode = fillIntoNode(root->leftNode, '{');
    } else if (firstScope == '[') {
        scopeKeeper.rv = scopeKeeper.rv + 1;
        root->rightNode = fillIntoNode(root->rightNode, '[');
    }
    char scope = loadCharacter();
    
    if (firstScope == '{' && scope == '{') {
        printf(""Invalid input"");
        exit(0);
    } else if (firstScope == '[' && scope == '[') {
        printf(""Invalid input"");
        exit(0);
    }
    if (scope == '{') {
        scopeKeeper.lv = scopeKeeper.lv + 1;
        root->leftNode = fillIntoNode(root->leftNode, '{');
    } else if (scope == '[') {
        scopeKeeper.rv = scopeKeeper.rv + 1;
        root->rightNode = fillIntoNode(root->rightNode, '[');
    }
    return root;
}

int main() {
    // So, when the root is non existant, but the rest is (it's got some nodes), the program will continue even though it should error out.
    // clever... yeah, for sure :D
    char buffer[1000];
    int counter = 0;
    char valueChar = loadCharacter();
    if (valueChar != '1' && valueChar != '2' && valueChar != '3' && valueChar != '4' && valueChar != '5' &&
        valueChar != '6' &&
        valueChar != '7' && valueChar != '8' && valueChar != '9' && valueChar != '0') {
        buffer[0] = valueChar;
    }
    while (valueChar == '1' || valueChar == '2' || valueChar == '3' || valueChar == '4' || valueChar == '5' ||
           valueChar == '6' ||
           valueChar == '7' || valueChar == '8' || valueChar == '9' || valueChar == '0') {
        buffer[counter] = valueChar;
        counter = counter + 1;
        valueChar = loadCharacter();
    }
    
    char scopeInner = valueChar;

    // Gets the length of value (eg. 123 -> 3)
    int sizeOfParsedNumberString = 0;
    for (int i = 0; i < sizeof buffer / sizeof buffer[0]; ++i) {
        if (buffer[i] == '1' || buffer[i] == '2' || buffer[i] == '3' || buffer[i] == '4' ||
            buffer[i] == '5' || buffer[i] == '6' ||
            buffer[i] == '7' || buffer[i] == '8' || buffer[i] == '9' || buffer[i] == '0') {
            sizeOfParsedNumberString = sizeOfParsedNumberString + 1;
        } else {
            break;
        }
    }

    int value;
    if (sizeOfParsedNumberString == 0) {
        if (buffer[0] == '{' || buffer[0] == '[' || buffer[0] == '}' || buffer[0] == ']') {
            printf(""Invalid input"");
            exit(0);
        }
        exit(0);
    } else {
        value = atoi(buffer);
    }

    if (sizeOfParsedNumberString >= 1) {
        struct Node *root = createNewNode(value);
        root = parseRoot(root, scopeInner);
        if (scopeKeeper.lv != 0 || scopeKeeper.rv != 0) {
            printf(""Invalid input"");
            exit(0);
        }
        printTreeInOrder(root);
    }
    return 0;
}"
Tree parsing and post-order traversal,"#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *leftNode;
    struct Node *rightNode;
};

struct valueLeftRight {
    int lv;
    int rv;
} scopeKeeper;

struct Node *createNewNode(int value) {
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    node->value = value;
    node->leftNode = NULL;
    node->rightNode = NULL;

    return node;
}

void printTreeInOrder(struct Node *node) {
    if (node == NULL)
        return;

    printTreeInOrder(node->leftNode);
    printTreeInOrder(node->rightNode);
    printf(""%d\n"", node->value);
}

char loadCharacter() {
    char charValue = getc(stdin);
    while (charValue == '\n' || charValue == ' ' || charValue == '\t') {
        charValue = getc(stdin);
    }
    return charValue;
}

struct Node *fillIntoNode(struct Node *node, char scope) {
    int oneMore = 0;
    if (scope != ' ') {
        oneMore = 1;
    }

    if (scope != '[' && scope != '{' && scope != ']' && scope != '}') {
        printf(""Invalid input"");
        exit(0);
    }

    // clever... yeah, for sure :D
    char numberString[1000];
    int counter = 0;
    char valueChar = loadCharacter();
    while (valueChar == '1' || valueChar == '2' || valueChar == '3' || valueChar == '4' || valueChar == '5' ||
           valueChar == '6' ||
           valueChar == '7' || valueChar == '8' || valueChar == '9' || valueChar == '0') {
        numberString[counter] = valueChar;
        counter = counter + 1;
        valueChar = loadCharacter();
    }

    char scopeInner = valueChar;

    // Gets the length of value (eg. 123 -> 3)
    int sizeOfParsedNumberString = 0;
    for (int i = 0; i < sizeof numberString / sizeof numberString[0]; ++i) {
        if (numberString[i] == '1' || numberString[i] == '2' || numberString[i] == '3' || numberString[i] == '4' ||
            numberString[i] == '5' || numberString[i] == '6' ||
            numberString[i] == '7' || numberString[i] == '8' || numberString[i] == '9' || numberString[i] == '0') {
            sizeOfParsedNumberString = sizeOfParsedNumberString + 1;
        } else {
            break;
        }
    }

    if (sizeOfParsedNumberString == 0) {
        printf(""Invalid input"");
        exit(0);
    }

    char *thisIsMandatoryButCommaItAddsStuffThatIsNotNumberHere;
    int value = strtol(numberString, &thisIsMandatoryButCommaItAddsStuffThatIsNotNumberHere, 10);

    // DESTROY THE ARRAY, OBLITERATE IT FROM THE FACE OF THE COMPILER (It doesn't work without this, I am not trying to be evil towards the non-pointer char array)
    // [and it doesn't even erase it, it just replaces all indexes with \000, which is some magical NULL value, or whatever]
    for (int i = 0; i < sizeof numberString / sizeof numberString[0]; ++i) {
        numberString[i] = '\000';
    }

    node = createNewNode(value);

    // inner scope -> opens another node
    if (scopeInner == '{') {
        scopeKeeper.lv = scopeKeeper.lv + 1;
        node->leftNode = createNewNode(0);
        node->leftNode = fillIntoNode(node->leftNode, '{');
    } else if (scopeInner == '[') {
        scopeKeeper.rv = scopeKeeper.rv + 1;
        node->rightNode = createNewNode(0);
        node->rightNode = fillIntoNode(node->rightNode, '[');
    }

    // inner scope -> closes current node 
    if (scopeInner != '{' && scopeInner != '[') {
        if (scope == '{' && scopeInner != '}') {
            printf(""Invalid input"");
            exit(0);
        } else if (scope == '[' && scopeInner != ']') {
            printf(""Invalid input"");
            exit(0);
        } else if (scope == '{' && scopeInner == '}') {
            scopeKeeper.lv = scopeKeeper.lv - 1;
            return node;
        } else if (scope == '[' && scopeInner == ']') {
            scopeKeeper.rv = scopeKeeper.rv - 1;
            return node;
        }
    }

    // This part of the code checks for possible second child node from the current node
    char scopeInner1 = loadCharacter();
    
    if (scopeInner == '{' && scopeInner1 == '{' || scopeInner == '[' && scopeInner1 == '[') {
        printf(""Invalid input"");
        exit(0);
    }
    
    // inner scope -> opens another node
    if (scopeInner1 == '{') {
        scopeKeeper.lv = scopeKeeper.lv + 1;
        node->leftNode = createNewNode(0);
        node->leftNode = fillIntoNode(node->leftNode, '{');
    } else if (scopeInner1 == '[') {
        scopeKeeper.rv = scopeKeeper.rv + 1;
        node->rightNode = createNewNode(0);
        node->rightNode = fillIntoNode(node->rightNode, '[');
    }

    // inner scope -> closes current node 
    if (scopeInner1 != '{' && scopeInner1 != '[') {
        if (scope == '{' && scopeInner1 != '}') {
            printf(""Invalid input"");
            exit(0);
        } else if (scope == '[' && scopeInner1 != ']') {
            printf(""Invalid input"");
            exit(0);
        } else if (scope == '{' && scopeInner1 == '}') {
            scopeKeeper.lv = scopeKeeper.lv - 1;
            return node;
        } else if (scope == '[' && scopeInner1 == ']') {
            scopeKeeper.rv = scopeKeeper.rv - 1;
            return node;
        }
    }

    // This part will need some more edge case handling, but basically,
    // If I pass a scope into fillIntoMagic, the logic makes it so it does not loadCharacter for the current node's scope
    // I could as well change it a bit, as there is no instance of me not passing in a scope, but,... yeah
    if (oneMore) {
        scopeInner = loadCharacter();
        if (scopeInner == '}') {
            scopeKeeper.lv = scopeKeeper.lv - 1;
        } else if (scopeInner == ']') {
            scopeKeeper.rv = scopeKeeper.rv - 1;
        }
    }
    return node;
}

struct Node *parseRoot(struct Node *root, char firstScope) {
    if (firstScope == '{') {
        scopeKeeper.lv = scopeKeeper.lv + 1;
        root->leftNode = fillIntoNode(root->leftNode, '{');
    } else if (firstScope == '[') {
        scopeKeeper.rv = scopeKeeper.rv + 1;
        root->rightNode = fillIntoNode(root->rightNode, '[');
    }
    char scope = loadCharacter();
    
    if (firstScope == '{' && scope == '{') {
        printf(""Invalid input"");
        exit(0);
    } else if (firstScope == '[' && scope == '[') {
        printf(""Invalid input"");
        exit(0);
    }
    if (scope == '{') {
        scopeKeeper.lv = scopeKeeper.lv + 1;
        root->leftNode = fillIntoNode(root->leftNode, '{');
    } else if (scope == '[') {
        scopeKeeper.rv = scopeKeeper.rv + 1;
        root->rightNode = fillIntoNode(root->rightNode, '[');
    }
    return root;
}

int main() {
    // So, when the root is non existant, but the rest is (it's got some nodes), the program will continue even though it should error out.
    // clever... yeah, for sure :D
    char buffer[1000];
    int counter = 0;
    char valueChar = loadCharacter();
    if (valueChar != '1' && valueChar != '2' && valueChar != '3' && valueChar != '4' && valueChar != '5' &&
        valueChar != '6' &&
        valueChar != '7' && valueChar != '8' && valueChar != '9' && valueChar != '0') {
        buffer[0] = valueChar;
    }
    while (valueChar == '1' || valueChar == '2' || valueChar == '3' || valueChar == '4' || valueChar == '5' ||
           valueChar == '6' ||
           valueChar == '7' || valueChar == '8' || valueChar == '9' || valueChar == '0') {
        buffer[counter] = valueChar;
        counter = counter + 1;
        valueChar = loadCharacter();
    }
    
    char scopeInner = valueChar;

    // Gets the length of value (eg. 123 -> 3)
    int sizeOfParsedNumberString = 0;
    for (int i = 0; i < sizeof buffer / sizeof buffer[0]; ++i) {
        if (buffer[i] == '1' || buffer[i] == '2' || buffer[i] == '3' || buffer[i] == '4' ||
            buffer[i] == '5' || buffer[i] == '6' ||
            buffer[i] == '7' || buffer[i] == '8' || buffer[i] == '9' || buffer[i] == '0') {
            sizeOfParsedNumberString = sizeOfParsedNumberString + 1;
        } else {
            break;
        }
    }

    int value;
    if (sizeOfParsedNumberString == 0) {
        if (buffer[0] == '{' || buffer[0] == '[' || buffer[0] == '}' || buffer[0] == ']') {
            printf(""Invalid input"");
            exit(0);
        }
        exit(0);
    } else {
        value = atoi(buffer);
    }

    if (sizeOfParsedNumberString >= 1) {
        struct Node *root = createNewNode(value);
        root = parseRoot(root, scopeInner);
        if (scopeKeeper.lv != 0 || scopeKeeper.rv != 0) {
            printf(""Invalid input"");
            exit(0);
        }
        printTreeInOrder(root);
    }
    return 0;
}"
Database search,"// Submitting what I've got
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Data {
    int year;
    int month;
    int day;
    char *name;
} Data;

struct Node {
    Data data;
    struct Node *leftNode;
    struct Node *rightNode;
};

struct Node *createNewNode(Data data) {
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    node->data = data;
    node->leftNode = NULL;
    node->rightNode = NULL;
    return node;
}

char *scanWord(char c, char *word) {
    int counter = 0;
    while (1) {
        scanf(""%c"", &c);
        if (c == '\n' || c == EOF) {
            return word;
        }
        word = realloc(word, counter + 1 * sizeof(char));
        word[counter++] = c;
        word[counter] = '\0';
    }
}

struct Node *store(struct Node *node, Data data) {
    if (node == NULL) {
        printf(""Stored\n"");
        return createNewNode(data);
    }

    int checkIfStored = strcmp(node->data.name, data.name);
    if (checkIfStored == 0 && node->data.year == data.year && data.month == node->data.month &&
        node->data.day == data.day) {
        printf(""Already stored\n"");
        return node;
    }

    if (node->data.year > data.year) {
        node->leftNode = store(node->leftNode, data);

    } else if (node->data.year < data.year) {
        node->rightNode = store(node->rightNode, data);
    }

    if (node->data.year == data.year) {

        if (node->data.month > data.month) {

            node->leftNode = store(node->leftNode, data);

        } else if (node->data.month < data.month) {
            node->rightNode = store(node->rightNode, data);
        }

        if (node->data.day > data.day) {
            node->leftNode = store(node->leftNode, data);

        } else if (node->data.day < data.day) {
            node->rightNode = store(node->rightNode, data);
        }

        int nameCheck = strcmp(node->data.name, data.name);
        if (nameCheck > 0) {
            node->leftNode = store(node->leftNode, data);
        } else if (nameCheck < 0) {
            node->rightNode = store(node->rightNode, data);
        }
    }
    return node;
}

int find(struct Node *node, Data data) {
    if (node == NULL)
        return 0;

    if (strcmp(node->data.name, data.name) == 0 && data.year == node->data.year && data.day == node->data.day &&
        data.month == node->data.month)
        return 1;

    if (find(node->leftNode, data)) return 1;

    return find(node->rightNode, data);
}

int main() {
    Data data;
    struct Node *root = NULL;
    char typeSymbol;
    while (scanf(""%c: "", &typeSymbol) != EOF) {
        data.name = scanWord(' ', malloc(sizeof(char)));
        if (typeSymbol == 'S') {
            root = store(root, data);
        } else if (typeSymbol == 'F') {
            if (find(root, data)) {
                printf(""Found\n"");
            } else {
                printf(""Not found\n"");
            }
        }
    }
    return 0;
}"
Database search,"// Submitting what I've got
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Data {
    int year;
    int month;
    int day;
    char *name;
} Data;

struct Node {
    Data data;
    struct Node *leftNode;
    struct Node *rightNode;
};

struct Node *createNewNode(Data data) {
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    node->data = data;
    node->leftNode = NULL;
    node->rightNode = NULL;
    return node;
}

char *scanWord(char c, char *word) {
    int counter = 0;
    while (1) {
        scanf(""%c"", &c);
        if (c == '\n' || c == EOF) {
            return word;
        }
        word = realloc(word, counter + 1 * sizeof(char));
        word[counter++] = c;
        word[counter] = '\0';
    }
}

struct Node* findLowestValueNode(struct Node* node)
{
    struct Node* currentNode = node;

    /* loop down to find the leftmost leaf */
    while (currentNode && currentNode->leftNode != NULL)
        currentNode = currentNode->leftNode;

    return currentNode;
}

struct Node *delete(struct Node *node, Data data) {
    if (node == NULL) {
        printf(""Deleted\n"");
        return node;
    }

    if (node->data.year > data.year) {
        node->leftNode = delete(node->leftNode, data);

    } else if (node->data.year < data.year) {
        node->rightNode = delete(node->rightNode, data);
    }

    if (node->data.year == data.year) {

        if (node->data.month > data.month) {

            node->leftNode = delete(node->leftNode, data);

        } else if (node->data.month < data.month) {
            node->rightNode = delete(node->rightNode, data);
        }

        if (node->data.day > data.day) {
            node->leftNode = delete(node->leftNode, data);

        } else if (node->data.day < data.day) {
            node->rightNode = delete(node->rightNode, data);
        }

        int nameCheck = strcmp(node->data.name, data.name);
        if (nameCheck > 0) {
            node->leftNode = delete(node->leftNode, data);
        } else if (nameCheck < 0) {
            node->rightNode = delete(node->rightNode, data);
        }
    }

    if (node->leftNode == NULL) {
        struct Node* temp = node->rightNode;
        free(node);
        return temp;
    } else if (node->rightNode == NULL) {
        struct Node* temp = node->leftNode;
        free(node);
        return temp;
    }

    struct Node* temp = findLowestValueNode(node->rightNode);
    node->data = temp->data;
    node->rightNode = delete(node->rightNode, temp->data);

    return node;
}

struct Node *store(struct Node *node, Data data) {
    if (node == NULL) {
        printf(""Stored\n"");
        return createNewNode(data);
    }

    int checkIfStored = strcmp(node->data.name, data.name);
    if (checkIfStored == 0 && node->data.year == data.year && data.month == node->data.month && node->data.day == data.day) {
        printf(""Already stored\n"");
        return node;
    }

    if (node->data.year > data.year) {
        node->leftNode = store(node->leftNode, data);

    } else if (node->data.year < data.year) {
        node->rightNode = store(node->rightNode, data);
    }

    if (node->data.year == data.year) {

        if (node->data.month > data.month) {

            node->leftNode = store(node->leftNode, data);

        } else if (node->data.month < data.month) {
            node->rightNode = store(node->rightNode, data);
        }

        if (node->data.day > data.day) {
            node->leftNode = store(node->leftNode, data);

        } else if (node->data.day < data.day) {
            node->rightNode = store(node->rightNode, data);
        }

        int nameCheck = strcmp(node->data.name, data.name);
        if (nameCheck > 0) {
            node->leftNode = store(node->leftNode, data);
        } else if (nameCheck < 0) {
            node->rightNode = store(node->rightNode, data);
        }
    }
    return node;
}

int find(struct Node *node, Data data) {
    if (node == NULL)
        return 0;

    if (strcmp(node->data.name, data.name) == 0 && data.year == node->data.year && data.day == node->data.day &&
        data.month == node->data.month)
        return 1;

    if (find(node->leftNode, data)) return 1;

    return find(node->rightNode, data);
}

int main() {
    Data data;
    struct Node *root = NULL;
    char typeSymbol;
    while (scanf(""%c: %d %d %d"", &typeSymbol, &data.year, &data.month, &data.day) != EOF) {
        data.name = scanWord(' ', malloc(sizeof(char)));
        if (typeSymbol == 'S') {
            root = store(root, data);
        } else if (typeSymbol == 'F') {
            if (find(root, data)) {
                printf(""Found\n"");
            } else {
                printf(""Not found\n"");
            }
        } else if (typeSymbol == 'D') {
            root = delete(root, data);
        }
    }
    return 0;
}"
Database search,"#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Data {
    int year;
    int month;
    int day;
    char *name;
} Data;

struct Node {
    Data data;
    struct Node *leftNode;
    struct Node *rightNode;
};

struct Node *createNewNode(Data data) {
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    node->data = data;
    node->leftNode = NULL;
    node->rightNode = NULL;
    return node;
}

char *scanWord(char c, char *word) {
    int counter = 0;
    while (1) {
        scanf(""%c"", &c);
        if (c == '\n' || c == EOF) {
            return word;
        }
        word = realloc(word, counter + 1 * sizeof(char));
        word[counter++] = c;
        word[counter] = '\0';
    }
}

struct Node *findLowestValueNode(struct Node *node) {
    struct Node *currentNode = node;

    /* loop down to find the leftmost leaf */
    while (currentNode && currentNode->leftNode != NULL)
        currentNode = currentNode->leftNode;

    return currentNode;
}

struct Node *delete(struct Node *node, Data data) {
    if (node == NULL) {
        printf(""Not found\n"");
        return node;
    }

    if (node->data.year > data.year) {
        node->leftNode = delete(node->leftNode, data);

    } else if (node->data.year < data.year) {
        node->rightNode = delete(node->rightNode, data);
    }

    if (node->data.year == data.year) {

        if (node->data.month > data.month) {

            node->leftNode = delete(node->leftNode, data);

        } else if (node->data.month < data.month) {
            node->rightNode = delete(node->rightNode, data);
        }

        if (node->data.day > data.day) {
            node->leftNode = delete(node->leftNode, data);

        } else if (node->data.day < data.day) {
            node->rightNode = delete(node->rightNode, data);
        }

        int nameCheck = strcmp(node->data.name, data.name);
        if (nameCheck > 0) {
            node->leftNode = delete(node->leftNode, data);
        } else if (nameCheck < 0) {
            node->rightNode = delete(node->rightNode, data);
        }
    }

    if (node->leftNode == NULL) {
        struct Node *temp = node->rightNode;
        free(node);
        return temp;
    } else if (node->rightNode == NULL) {
        struct Node *temp = node->leftNode;
        free(node);
        return temp;
    }

    struct Node *temp = findLowestValueNode(node->rightNode);
    node->data = temp->data;
    node->rightNode = delete(node->rightNode, temp->data);

    printf(""Deleted\n"");
    return node;
}

struct Node *store(struct Node *node, Data data) {
    if (node == NULL) {
        printf(""Stored\n"");
        return createNewNode(data);
    }

    int checkIfStored = strcmp(node->data.name, data.name);
    if (checkIfStored == 0 && node->data.year == data.year && data.month == node->data.month &&
        node->data.day == data.day) {
        printf(""Already stored\n"");
        return node;
    }

    if (node->data.year > data.year) {
        node->leftNode = store(node->leftNode, data);

    } else if (node->data.year < data.year) {
        node->rightNode = store(node->rightNode, data);
    }

    if (node->data.year == data.year) {

        if (node->data.month > data.month) {

            node->leftNode = store(node->leftNode, data);

        } else if (node->data.month < data.month) {
            node->rightNode = store(node->rightNode, data);
        }

        if (node->data.day > data.day) {
            node->leftNode = store(node->leftNode, data);

        } else if (node->data.day < data.day) {
            node->rightNode = store(node->rightNode, data);
        }

        int nameCheck = strcmp(node->data.name, data.name);
        if (nameCheck > 0) {
            node->leftNode = store(node->leftNode, data);
        } else if (nameCheck < 0) {
            node->rightNode = store(node->rightNode, data);
        }
    }
    return node;
}

int find(struct Node *node, Data data) {
    if (node == NULL)
        return 0;

    if (strcmp(node->data.name, data.name) == 0 && data.year == node->data.year && data.day == node->data.day &&
        data.month == node->data.month)
        return 1;

    if (find(node->leftNode, data)) return 1;

    return find(node->rightNode, data);
}

int main() {
    Data data;
    struct Node *root = NULL;
    char typeSymbol;
    while (scanf(""%c: %d %d %d"", &typeSymbol, &data.year, &data.month, &data.day) != EOF) {
        data.name = scanWord(' ', malloc(sizeof(char)));
        if (typeSymbol == 'S') {
            root = store(root, data);
        } else if (typeSymbol == 'F') {
            if (find(root, data)) {
                printf(""Found\n"");
            } else {
                printf(""Not found\n"");
            }
        } else if (typeSymbol == 'D') {
            root = delete(root, data);
        }
    }
    return 0;
}"
Database search,"#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Data {
    int year;
    int month;
    int day;
    char *name;
} Data;

struct shouldWriteDeleted {
    int should;
} shouldWriteDeleted;

struct Node {
    Data data;
    struct Node *leftNode;
    struct Node *rightNode;
};

struct Node *createNewNode(Data data) {
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    node->data = data;
    node->leftNode = NULL;
    node->rightNode = NULL;
    return node;
}

char *scanWord(char c, char *word) {
    int counter = 0;
    while (1) {
        scanf(""%c"", &c);
        if (c == '\n' || c == EOF) {
            return word;
        }
        word = realloc(word, counter + 1 * sizeof(char));
        word[counter++] = c;
        word[counter] = '\0';
    }
}

struct Node *findLowestValueNode(struct Node *node) {
    struct Node *currentNode = node;

    /* loop down to find the leftmost leaf */
    while (currentNode && currentNode->leftNode != NULL)
        currentNode = currentNode->leftNode;

    return currentNode;
}

struct Node *delete(struct Node *node, Data data) {
    if (node == NULL) {
        printf(""Not found\n"");
        shouldWriteDeleted.should = 0;
        return node;
    }

    if (node->data.year > data.year) {
        node->leftNode = delete(node->leftNode, data);

    } else if (node->data.year < data.year) {
        node->rightNode = delete(node->rightNode, data);
    }

    if (node->data.year == data.year) {

        if (node->data.month > data.month) {

            node->leftNode = delete(node->leftNode, data);

        } else if (node->data.month < data.month) {
            node->rightNode = delete(node->rightNode, data);
        }

        if (node->data.day > data.day) {
            node->leftNode = delete(node->leftNode, data);

        } else if (node->data.day < data.day) {
            node->rightNode = delete(node->rightNode, data);
        }

        int nameCheck = strcmp(node->data.name, data.name);
        if (nameCheck > 0) {
            node->leftNode = delete(node->leftNode, data);
        } else if (nameCheck < 0) {
            node->rightNode = delete(node->rightNode, data);
        }
    }

    if (node->leftNode == NULL) {
        struct Node *temp = node->rightNode;
        free(node);
        return temp;
    } else if (node->rightNode == NULL) {
        struct Node *temp = node->leftNode;
        free(node);
        return temp;
    }

    struct Node *temp = findLowestValueNode(node->rightNode);
    node->data = temp->data;
    node->rightNode = delete(node->rightNode, temp->data);

    return node;
}

struct Node *store(struct Node *node, Data data) {
    if (node == NULL) {
        printf(""Stored\n"");
        return createNewNode(data);
    }

    int checkIfStored = strcmp(node->data.name, data.name);
    if (checkIfStored == 0 && node->data.year == data.year && data.month == node->data.month &&
        node->data.day == data.day) {
        printf(""Already stored\n"");
        return node;
    }

    if (node->data.year > data.year) {
        node->leftNode = store(node->leftNode, data);

    } else if (node->data.year < data.year) {
        node->rightNode = store(node->rightNode, data);
    }

    if (node->data.year == data.year) {

        if (node->data.month > data.month) {

            node->leftNode = store(node->leftNode, data);

        } else if (node->data.month < data.month) {
            node->rightNode = store(node->rightNode, data);
        }

        if (node->data.day > data.day) {
            node->leftNode = store(node->leftNode, data);

        } else if (node->data.day < data.day) {
            node->rightNode = store(node->rightNode, data);
        }

        int nameCheck = strcmp(node->data.name, data.name);
        if (nameCheck > 0) {
            node->leftNode = store(node->leftNode, data);
        } else if (nameCheck < 0) {
            node->rightNode = store(node->rightNode, data);
        }
    }
    return node;
}

int find(struct Node *node, Data data) {
    if (node == NULL)
        return 0;

    if (strcmp(node->data.name, data.name) == 0 && data.year == node->data.year && data.day == node->data.day &&
        data.month == node->data.month)
        return 1;

    if (find(node->leftNode, data)) return 1;

    return find(node->rightNode, data);
}

int main() {
    Data data;
    struct Node *root = NULL;
    char typeSymbol;
    while (scanf(""%c: %d %d %d"", &typeSymbol, &data.year, &data.month, &data.day) != EOF) {
        data.name = scanWord(' ', malloc(sizeof(char)));
        if (typeSymbol == 'S') {
            root = store(root, data);
        } else if (typeSymbol == 'F') {
            if (find(root, data)) {
                printf(""Found\n"");
            } else {
                printf(""Not found\n"");
            }
        } else if (typeSymbol == 'D') {
            shouldWriteDeleted.should = 1;
            root = delete(root, data);
            if (shouldWriteDeleted.should) {
                printf(""Deleted\n"");
            }
        }
    }
    return 0;
}"
Database search,"#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Data {
    int year;
    int month;
    int day;
    char *name;
} Data;

struct shouldWriteDeleted {
    int should;
} shouldWriteDeleted;

struct Node {
    Data data;
    struct Node *leftNode;
    struct Node *rightNode;
};

struct Node *createNewNode(Data data) {
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    node->data = data;
    node->leftNode = NULL;
    node->rightNode = NULL;
    return node;
}

char *scanWord(char c, char *word) {
    int counter = 0;
    while (1) {
        scanf(""%c"", &c);
        if (c == '\n' || c == EOF) {
            return word;
        }
        word = realloc(word, counter + 1 * sizeof(char));
        word[counter++] = c;
        word[counter] = '\0';
    }
}

struct Node *findLowestValueNode(struct Node *node) {
    struct Node *currentNode = node;

    /* loop down to find the leftmost leaf */
    while (currentNode && currentNode->leftNode != NULL) {
        currentNode = currentNode->leftNode;
    }

    return currentNode;
}

struct Node *delete(struct Node *node, Data data) {
    if (node == NULL) {
        printf(""Not found\n"");
        shouldWriteDeleted.should = 0;
        return node;
    }

    if (node->data.year > data.year) {
        node->leftNode = delete(node->leftNode, data);

    } else if (node->data.year < data.year) {
        node->rightNode = delete(node->rightNode, data);
    }

    if (node->data.year == data.year) {

        if (node->data.month > data.month) {

            node->leftNode = delete(node->leftNode, data);

        } else if (node->data.month < data.month) {
            node->rightNode = delete(node->rightNode, data);
        }

        if (node->data.day > data.day) {
            node->leftNode = delete(node->leftNode, data);

        } else if (node->data.day < data.day) {
            node->rightNode = delete(node->rightNode, data);
        }

        int nameCheck = strcmp(node->data.name, data.name);
        if (nameCheck > 0) {
            node->leftNode = delete(node->leftNode, data);
        } else if (nameCheck < 0) {
            node->rightNode = delete(node->rightNode, data);
        }
    }

    if (node->leftNode == NULL) {
        struct Node *temp = node->rightNode;
        free(node);
        return temp;
    } else if (node->rightNode == NULL) {
        struct Node *temp = node->leftNode;
        free(node);
        return temp;
    }

    struct Node *temp = findLowestValueNode(node->rightNode);
    node->data = temp->data;
    node->rightNode = delete(node->rightNode, temp->data);

    return node;
}

struct Node *store(struct Node *node, Data data) {
    if (node == NULL) {
        printf(""Stored\n"");
        return createNewNode(data);
    }

    int checkIfStored = strcmp(node->data.name, data.name);
    if (checkIfStored == 0 && node->data.year == data.year && data.month == node->data.month &&
        node->data.day == data.day) {
        printf(""Already stored\n"");
        return node;
    }

    if (node->data.year > data.year) {
        node->leftNode = store(node->leftNode, data);

    } else if (node->data.year < data.year) {
        node->rightNode = store(node->rightNode, data);
    }

    if (node->data.year == data.year) {

        if (node->data.month > data.month) {

            node->leftNode = store(node->leftNode, data);

        } else if (node->data.month < data.month) {
            node->rightNode = store(node->rightNode, data);
        }

        if (node->data.day > data.day) {
            node->leftNode = store(node->leftNode, data);

        } else if (node->data.day < data.day) {
            node->rightNode = store(node->rightNode, data);
        }

        int nameCheck = strcmp(node->data.name, data.name);
        if (nameCheck > 0) {
            node->leftNode = store(node->leftNode, data);
        } else if (nameCheck < 0) {
            node->rightNode = store(node->rightNode, data);
        }
    }
    return node;
}

int find(struct Node *node, Data data) {
    if (node == NULL)
        return 0;

    if (strcmp(node->data.name, data.name) == 0 && data.year == node->data.year && data.day == node->data.day &&
        data.month == node->data.month)
        return 1;

    if (find(node->leftNode, data)) return 1;

    return find(node->rightNode, data);
}

int main() {
    Data data;
    struct Node *root = NULL;
    char typeSymbol;
    while (scanf(""%c: %d %d %d "", &typeSymbol, &data.year, &data.month, &data.day) != EOF) {
        data.name = scanWord(' ', malloc(sizeof(char)));
        if (typeSymbol == 'S') {
            root = store(root, data);
        } else if (typeSymbol == 'F') {
            if (find(root, data)) {
                printf(""Found\n"");
            } else {
                printf(""Not found\n"");
            }
        } else if (typeSymbol == 'D') {
            shouldWriteDeleted.should = 1;
            root = delete(root, data);
            if (shouldWriteDeleted.should) {
                printf(""Deleted\n"");
            }
        }
    }
    return 0;
}"
Database search,"#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Data {
    int year;
    int month;
    int day;
    char *name;
} Data;

struct logicalPrint {
    int deleteDeleted;
    int deleteNotFound;
    int storeStored;
    int storeAlreadyStored;
} logicalPrint;

struct Node {
    Data data;
    struct Node *leftNode;
    struct Node *rightNode;
};

struct Node *createNewNode(Data data) {
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    node->data = data;
    node->leftNode = NULL;
    node->rightNode = NULL;
    return node;
}

char *scanWord(char c, char *word) {
    int counter = 0;
    while (1) {
        scanf(""%c"", &c);
        if (c == '\n' || c == EOF) {
            return word;
        }
        word = realloc(word, counter + 1 * sizeof(char));
        word[counter++] = c;
        word[counter] = '\0';
    }
}

struct Node *findLowestValueNode(struct Node *node) {
    struct Node *currentNode = node;

    /* loop down to find the leftmost leaf */
    while (currentNode && currentNode->leftNode != NULL) {
        currentNode = currentNode->leftNode;
    }

    return currentNode;
}

struct Node *delete(struct Node *node, Data data) {
    if (node == NULL) {
        logicalPrint.deleteNotFound = 1;
        logicalPrint.deleteDeleted = 0;
        return node;
    }

    if (node->data.year > data.year) {
        node->leftNode = delete(node->leftNode, data);

    } else if (node->data.year < data.year) {
        node->rightNode = delete(node->rightNode, data);
    }

    if (node->data.year == data.year) {

        if (node->data.month > data.month) {

            node->leftNode = delete(node->leftNode, data);

        } else if (node->data.month < data.month) {
            node->rightNode = delete(node->rightNode, data);
        }

        if (node->data.day > data.day) {
            node->leftNode = delete(node->leftNode, data);

        } else if (node->data.day < data.day) {
            node->rightNode = delete(node->rightNode, data);
        }

        int nameCheck = strcmp(node->data.name, data.name);
        if (nameCheck > 0) {
            node->leftNode = delete(node->leftNode, data);
        } else if (nameCheck < 0) {
            node->rightNode = delete(node->rightNode, data);
        }
    }

    if (node->leftNode == NULL) {
        struct Node *temp = node->rightNode;
        free(node);
        return temp;
    } else if (node->rightNode == NULL) {
        struct Node *temp = node->leftNode;
        free(node);
        return temp;
    }

    struct Node *temp = findLowestValueNode(node->rightNode);
    node->data = temp->data;
    node->rightNode = delete(node->rightNode, temp->data);

    return node;
}

struct Node *store(struct Node *node, Data data) {
    if (node == NULL) {
        logicalPrint.storeStored = 1;
        return createNewNode(data);
    }

    int checkIfStored = strcmp(node->data.name, data.name);
    if (checkIfStored == 0 && node->data.year == data.year && data.month == node->data.month &&
        node->data.day == data.day) {
        logicalPrint.storeAlreadyStored = 1;
        return node;
    }

    if (node->data.year > data.year) {
        node->leftNode = store(node->leftNode, data);

    } else if (node->data.year < data.year) {
        node->rightNode = store(node->rightNode, data);
    }

    if (node->data.year == data.year) {

        if (node->data.month > data.month) {

            node->leftNode = store(node->leftNode, data);

        } else if (node->data.month < data.month) {
            node->rightNode = store(node->rightNode, data);
        }

        if (node->data.day > data.day) {
            node->leftNode = store(node->leftNode, data);

        } else if (node->data.day < data.day) {
            node->rightNode = store(node->rightNode, data);
        }

        int nameCheck = strcmp(node->data.name, data.name);
        if (nameCheck > 0) {
            node->leftNode = store(node->leftNode, data);
        } else if (nameCheck < 0) {
            node->rightNode = store(node->rightNode, data);
        }
    }
    return node;
}

int find(struct Node *node, Data data) {
    if (node == NULL)
        return 0;

    if (strcmp(node->data.name, data.name) == 0 && data.year == node->data.year && data.day == node->data.day &&
        data.month == node->data.month)
        return 1;

    if (find(node->leftNode, data)) return 1;

    return find(node->rightNode, data);
}

int main() {
    Data data;
    struct Node *root = NULL;
    char typeSymbol;
    while (scanf(""%c: %d %d %d "", &typeSymbol, &data.year, &data.month, &data.day) != EOF) {
        data.name = scanWord(' ', malloc(sizeof(char)));
        if (typeSymbol == 'S') {
            logicalPrint.storeStored = 0;
            logicalPrint.storeAlreadyStored = 0;
            root = store(root, data);
            if (logicalPrint.storeStored) {
                printf(""Stored\n"");
            }
            if (logicalPrint.storeAlreadyStored) {
                printf(""Already stored\n"");
            }
        } else if (typeSymbol == 'F') {
            if (find(root, data)) {
                printf(""Found\n"");
            } else {
                printf(""Not found\n"");
            }
        } else if (typeSymbol == 'D') {
            logicalPrint.deleteDeleted = 1;
            logicalPrint.deleteNotFound = 0;
            root = delete(root, data);
            if (logicalPrint.deleteDeleted) {
                printf(""Deleted\n"");
            }
            if (logicalPrint.deleteNotFound) {
                printf(""Not found\n"");
            }
        }
    }
    return 0;
}"
Database search,"#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Data {
    int year;
    int month;
    int day;
    char *name;
} Data;

struct logicalPrint {
    int deleteDeleted;
    int deleteNotFound;
    int storeStored;
    int storeAlreadyStored;
} logicalPrint;

struct Node {
    Data data;
    struct Node *leftNode;
    struct Node *rightNode;
};

struct Node *createNewNode(Data data) {
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    node->data = data;
    node->leftNode = NULL;
    node->rightNode = NULL;
    return node;
}

char *scanWord(char c, char *word) {
    int counter = 0;
    while (1) {
        scanf(""%c"", &c);
        if (c == '\n' || c == EOF) {
            return word;
        }
        word = realloc(word, counter + 1 * sizeof(char));
        word[counter++] = c;
        word[counter] = '\0';
    }
}

struct Node *findLowestValueNode(struct Node *node) {
    struct Node *currentNode = node;

    /* loop down to find the leftmost leaf */
    while (currentNode && currentNode->leftNode != NULL) {
        currentNode = currentNode->leftNode;
    }

    return currentNode;
}

struct Node *delete(struct Node *node, Data data) {
    if (node == NULL) {
        logicalPrint.deleteNotFound = 1;
        logicalPrint.deleteDeleted = 0;
        return node;
    }

    if (node->data.year > data.year) {
        node->leftNode = delete(node->leftNode, data);

    } else if (node->data.year < data.year) {
        node->rightNode = delete(node->rightNode, data);
    }

    if (node->data.year == data.year) {

        if (node->data.month > data.month) {

            node->leftNode = delete(node->leftNode, data);

        } else if (node->data.month < data.month) {
            node->rightNode = delete(node->rightNode, data);
        }

        if (node->data.day > data.day) {
            node->leftNode = delete(node->leftNode, data);

        } else if (node->data.day < data.day) {
            node->rightNode = delete(node->rightNode, data);
        }

        int nameCheck = strcmp(node->data.name, data.name);
        if (nameCheck > 0) {
            node->leftNode = delete(node->leftNode, data);
        } else if (nameCheck < 0) {
            node->rightNode = delete(node->rightNode, data);
        }
    }

    if (node->leftNode == NULL) {
        struct Node *temp = node->rightNode;
        free(node);
        return temp;
    } else if (node->rightNode == NULL) {
        struct Node *temp = node->leftNode;
        free(node);
        return temp;
    }

    struct Node *temp = findLowestValueNode(node->rightNode);
    node->data = temp->data;
    node->rightNode = delete(node->rightNode, temp->data);

    return node;
}

struct Node *store(struct Node *node, Data data) {
    if (node == NULL) {
        logicalPrint.storeStored = 1;
        return createNewNode(data);
    }

    int checkIfStored = strcmp(node->data.name, data.name);
    if (checkIfStored == 0 && node->data.year == data.year && data.month == node->data.month &&
        node->data.day == data.day) {
        logicalPrint.storeAlreadyStored = 1;
        return node;
    }

    if (node->data.year > data.year) {
        node->leftNode = store(node->leftNode, data);

    } else if (node->data.year < data.year) {
        node->rightNode = store(node->rightNode, data);
    }

    if (node->data.year == data.year) {

        if (node->data.month > data.month) {

            node->leftNode = store(node->leftNode, data);

        } else if (node->data.month < data.month) {
            node->rightNode = store(node->rightNode, data);
        }

        if (node->data.day > data.day) {
            node->leftNode = store(node->leftNode, data);

        } else if (node->data.day < data.day) {
            node->rightNode = store(node->rightNode, data);
        }

        int nameCheck = strcmp(node->data.name, data.name);
        if (nameCheck > 0) {
            node->leftNode = store(node->leftNode, data);
        } else if (nameCheck < 0) {
            node->rightNode = store(node->rightNode, data);
        }
    }
    return node;
}

int find(struct Node *node, Data data) {
    if (node == NULL)
        return 0;

    if (strcmp(node->data.name, data.name) == 0 && data.year == node->data.year && data.day == node->data.day &&
        data.month == node->data.month)
        return 1;

    if (find(node->leftNode, data)) return 1;

    return find(node->rightNode, data);
}
// why does scanWord take that char argument
int main() {
    Data data;
    struct Node *root = NULL;
    char typeSymbol;
    while (scanf(""%c: %d %d %d "", &typeSymbol, &data.year, &data.month, &data.day) != EOF) {
        data.name = scanWord(' ', malloc(sizeof(char)));
        if (typeSymbol == 'S') {
            logicalPrint.storeStored = 0;
            logicalPrint.storeAlreadyStored = 0;
            root = store(root, data);
            if (logicalPrint.storeAlreadyStored) {
                printf(""Already stored\n"");
            }
            else if (logicalPrint.storeStored) {
                printf(""Stored\n"");
            }
        } else if (typeSymbol == 'F') {
            if (find(root, data)) {
                printf(""Found\n"");
            } else {
                printf(""Not found\n"");
            }
        } else if (typeSymbol == 'D') {
            logicalPrint.deleteDeleted = 1;
            logicalPrint.deleteNotFound = 0;
            root = delete(root, data);
            if (logicalPrint.deleteNotFound) {
                printf(""Not found\n"");
            }
            else if (logicalPrint.deleteDeleted) {
                printf(""Deleted\n"");
            }

        }
    }
    return 0;
}"
Database search,"#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Data {
    int year;
    int month;
    int day;
    char *name;
} Data;

struct Node {
    Data data;
    struct Node *leftNode;
    struct Node *rightNode;
};

struct Node *createNewNode(Data data) {
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    node->data = data;
    node->leftNode = NULL;
    node->rightNode = NULL;
    return node;
}

char *scanWord(char c, char *word) {
    int counter = 0;
    while (1) {
        scanf(""%c"", &c);
        if (c == '\n' || c == EOF) {
            return word;
        }
        word = realloc(word, counter + 1 * sizeof(char));
        word[counter++] = c;
        word[counter] = '\0';
    }
}

struct Node *findLowestValueNode(struct Node *node) {
    struct Node *currentNode = node;

    /* loop down to find the leftmost leaf */
    while (currentNode && currentNode->leftNode != NULL) {
        currentNode = currentNode->leftNode;
    }

    return currentNode;
}

struct Node *delete(struct Node *node, Data data, int *isDeleted) {
    if (node == NULL) {
        *isDeleted = 0;
        return node;
    }

    if (node->data.year > data.year) {
        node->leftNode = delete(node->leftNode, data, isDeleted);

    } else if (node->data.year < data.year) {
        node->rightNode = delete(node->rightNode, data, isDeleted);
    }

    if (node->data.year == data.year) {

        if (node->data.month > data.month) {

            node->leftNode = delete(node->leftNode, data, isDeleted);

        } else if (node->data.month < data.month) {
            node->rightNode = delete(node->rightNode, data, isDeleted);
        }

        if (node->data.day > data.day) {
            node->leftNode = delete(node->leftNode, data, isDeleted);

        } else if (node->data.day < data.day) {
            node->rightNode = delete(node->rightNode, data, isDeleted);
        }

        int nameCheck = strcmp(node->data.name, data.name);
        if (nameCheck > 0) {
            node->leftNode = delete(node->leftNode, data, isDeleted);
        } else if (nameCheck < 0) {
            node->rightNode = delete(node->rightNode, data, isDeleted);
        }
    }

    if (node->leftNode == NULL) {
        struct Node *temp = node->rightNode;
        free(node);
        return temp;
    } else if (node->rightNode == NULL) {
        struct Node *temp = node->leftNode;
        free(node);
        return temp;
    }

    struct Node *temp = findLowestValueNode(node->rightNode);
    node->data = temp->data;
    node->rightNode = delete(node->rightNode, temp->data, isDeleted);

    return node;
}

struct Node *store(struct Node *node, Data data, int *isStored) {
    if (node == NULL) {
        *isStored = 1;
        return createNewNode(data);
    }

    int checkIfStored = strcmp(node->data.name, data.name);
    if (checkIfStored == 0 && node->data.year == data.year && data.month == node->data.month &&
        node->data.day == data.day) {
        *isStored = 0;
        return node;
    }

    if (node->data.year > data.year) {
        node->leftNode = store(node->leftNode, data, isStored);

    } else if (node->data.year < data.year) {
        node->rightNode = store(node->rightNode, data, isStored);
    }

    if (node->data.year == data.year) {

        if (node->data.month > data.month) {

            node->leftNode = store(node->leftNode, data, isStored);

        } else if (node->data.month < data.month) {
            node->rightNode = store(node->rightNode, data, isStored);
        }

        if (node->data.day > data.day) {
            node->leftNode = store(node->leftNode, data, isStored);

        } else if (node->data.day < data.day) {
            node->rightNode = store(node->rightNode, data, isStored);
        }

        int nameCheck = strcmp(node->data.name, data.name);
        if (nameCheck > 0) {
            node->leftNode = store(node->leftNode, data, isStored);
        } else if (nameCheck < 0) {
            node->rightNode = store(node->rightNode, data, isStored);
        }
    }
    return node;
}

int find(struct Node *node, Data data) {
    if (node == NULL)
        return 0;

    if (strcmp(node->data.name, data.name) == 0 && data.year == node->data.year && data.day == node->data.day &&
        data.month == node->data.month)
        return 1;

    if (find(node->leftNode, data)) return 1;

    return find(node->rightNode, data);
}

// why does scanWord take that char argument
int main() {
    Data data;
    struct Node *root = NULL;
    char typeSymbol;
    while (scanf(""%c: %d %d %d "", &typeSymbol, &data.year, &data.month, &data.day) != EOF) {
        data.name = scanWord(' ', malloc(sizeof(char)));
        if (typeSymbol == 'S') {
            int isStored;
            root = store(root, data, &isStored);
            if (isStored == 1) {
                printf(""Stored\n"");
            } else if (isStored == 0) {
                printf(""Already stored\n"");
            }
        } else if (typeSymbol == 'F') {
            if (find(root, data)) {
                printf(""Found\n"");
            } else {
                printf(""Not found\n"");
            }
        } else if (typeSymbol == 'D') {
            int isDeleted = 1;
            root = delete(root, data, &isDeleted);
            if (isDeleted == 1) {
                printf(""Deleted\n"");
            } else if (isDeleted == 0) {
                printf(""Not found\n"");
            }

        }
    }
    return 0;
}"
Database search,"#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Data {
    int year;
    int month;
    int day;
    char *name;
} Data;

struct Node {
    Data data;
    struct Node *leftNode;
    struct Node *rightNode;
};

struct Node *createNewNode(Data data) {
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    node->data = data;
    node->leftNode = NULL;
    node->rightNode = NULL;
    return node;
}

char *scanWord(char c, char *word) {
    int counter = 0;
    while (1) {
        scanf(""%c"", &c);
        if (c == '\n' || c == EOF) {
            return word;
        }
        word = realloc(word, counter + 1 * sizeof(char));
        word[counter++] = c;
        word[counter] = '\0';
    }
}

struct Node *findLowestValueNode(struct Node *node) {
    struct Node *currentNode = node;

    /* loop down to find the leftmost leaf */
    while (currentNode && currentNode->leftNode != NULL) {
        currentNode = currentNode->leftNode;
    }

    return currentNode;
}

int compare(Data currentNode, Data loadedData) {
    int stringCompare;
    if (currentNode.year == loadedData.year) {
        if (currentNode.month == loadedData.month) {
            if (currentNode.day == loadedData.day) {
                stringCompare = strcmp(currentNode.name, loadedData.name);
                if (stringCompare == 0) {
                    return 0;
                } else if (stringCompare == 1) {
                    return 1;
                } else {
                    return -1;
                }
            } else if (currentNode.day > loadedData.day) {
                return 1;
            } else {
                return -1;
            }
        } else if (currentNode.month > loadedData.month) {
            return 1;
        } else {
            return -1;
        }
    } else if (currentNode.year > loadedData.year) {
        return 1;
    } else {
        return -1;
    }
}

struct Node *delete(struct Node *node, Data data, int *isDeleted) {
    if (node == NULL) {
        *isDeleted = 0;
        return node;
    }

    int comparison = compare(node->data, data);

    if (comparison == 0) {
        if (node->leftNode == NULL) {
            struct Node *temp = node->rightNode;
            free(node);
            return temp;
        } else if (node->rightNode == NULL) {
            struct Node *temp = node->leftNode;
            free(node);
            return temp;
        }

        struct Node *temp = findLowestValueNode(node->rightNode);
        node->data = temp->data;
        node->rightNode = delete(node->rightNode, temp->data, isDeleted);
    } else if (comparison > 0) {
        node->leftNode = delete(node->leftNode, data, isDeleted);
    } else {
        node->rightNode = delete(node->rightNode, data, isDeleted);
    }


    return node;
}

// the if structures badly. eve nafter creating a node, it goes onto creating another one

struct Node *store(struct Node *node, Data data, int *isStored) {
    if (node == NULL) {
        *isStored = 1;
        return createNewNode(data);
    }

    int checkIfStored = strcmp(node->data.name, data.name);
    if (checkIfStored == 0 && node->data.year == data.year && data.month == node->data.month &&
        node->data.day == data.day) {
        *isStored = 0;
        return node;
    }

    if (compare(node->data, data) > 0) {
        node->leftNode = store(node->leftNode, data, isStored);
    } else {
        node->rightNode = store(node->rightNode, data, isStored);
    }

// compare(node, data);
//    if (node->data.year > data.year) {
//        node->leftNode = store(node->leftNode, data, isStored);
//
//    } else if (node->data.year < data.year) {
//        node->rightNode = store(node->rightNode, data, isStored);
//    }
//
//    if (node->data.year == data.year) {
//
//        if (node->data.month > data.month) {
//
//            node->leftNode = store(node->leftNode, data, isStored);
//
//        } else if (node->data.month < data.month) {
//            node->rightNode = store(node->rightNode, data, isStored);
//        }
//
//        if (node->data.day > data.day) {
//            node->leftNode = store(node->leftNode, data, isStored);
//
//        } else if (node->data.day < data.day) {
//            node->rightNode = store(node->rightNode, data, isStored);
//        }
//
//        int nameCheck = strcmp(node->data.name, data.name);
//        if (nameCheck > 0) {
//            node->leftNode = store(node->leftNode, data, isStored);
//        } else if (nameCheck < 0) {
//            node->rightNode = store(node->rightNode, data, isStored);
//        }
//    }
    return node;
}

int find(struct Node *node, Data data) {
    if (node == NULL)
        return 0;

    if (strcmp(node->data.name, data.name) == 0 && data.year == node->data.year && data.day == node->data.day &&
        data.month == node->data.month)
        return 1;

    if (find(node->leftNode, data)) return 1;

    return find(node->rightNode, data);
}

// why does scanWord take that char argument
int main() {
    Data data;
    struct Node *root = NULL;
    char typeSymbol;
    while (scanf(""%c: %d %d %d "", &typeSymbol, &data.year, &data.month, &data.day) != EOF) {
        data.name = scanWord(' ', malloc(sizeof(char)));
        if (typeSymbol == 'S') {
            int isStored;
            root = store(root, data, &isStored);
            if (isStored == 1) {
                printf(""Stored\n"");
            } else if (isStored == 0) {
                printf(""Already stored\n"");
            }
        } else if (typeSymbol == 'F') {
            if (find(root, data)) {
                printf(""Found\n"");
            } else {
                printf(""Not found\n"");
            }
        } else if (typeSymbol == 'D') {
            int isDeleted = 1;
            root = delete(root, data, &isDeleted);
            if (isDeleted == 1) {
                printf(""Deleted\n"");
            } else if (isDeleted == 0) {
                printf(""Not found\n"");
            }
        }
    }
    return 0;
}"
Database search,"#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Data {
    int year;
    int month;
    int day;
    char *name;
} Data;

struct Node {
    Data data;
    struct Node *leftNode;
    struct Node *rightNode;
};

struct Node *createNewNode(Data data) {
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    node->data = data;
    node->leftNode = NULL;
    node->rightNode = NULL;
    return node;
}

char *scanWord(char c, char *word) {
    int counter = 0;
    while (1) {
        scanf(""%c"", &c);
        if (c == '\n' || c == EOF) {
            return word;
        }
        word = realloc(word, counter + 1 * sizeof(char));
        word[counter++] = c;
        word[counter] = '\0';
    }
}

struct Node *findLowestValueNode(struct Node *node) {
    struct Node *currentNode = node;

    /* loop down to find the leftmost leaf */
    while (currentNode && currentNode->leftNode != NULL) {
        currentNode = currentNode->leftNode;
    }

    return currentNode;
}

int compare(Data currentNode, Data loadedData) {
    int stringCompare;
    if (currentNode.year == loadedData.year) {
        if (currentNode.month == loadedData.month) {
            if (currentNode.day == loadedData.day) {
                stringCompare = strcmp(currentNode.name, loadedData.name);
                if (stringCompare == 0) {
                    return 0;
                } else if (stringCompare == 1) {
                    return 1;
                } else {
                    return -1;
                }
            } else if (currentNode.day > loadedData.day) {
                return 1;
            } else {
                return -1;
            }
        } else if (currentNode.month > loadedData.month) {
            return 1;
        } else {
            return -1;
        }
    } else if (currentNode.year > loadedData.year) {
        return 1;
    } else {
        return -1;
    }
}

struct Node *delete(struct Node *node, Data data, int *isDeleted) {
    if (node == NULL) {
        *isDeleted = 0;
        return node;
    }

    int comparison = compare(node->data, data);

    if (comparison == 0) {
        if (node->leftNode == NULL) {
            struct Node *temp = node->rightNode;
            free(node);
            return temp;
        } else if (node->rightNode == NULL) {
            struct Node *temp = node->leftNode;
            free(node);
            return temp;
        }

        struct Node *temp = findLowestValueNode(node->rightNode);
        node->data = temp->data;
        node->rightNode = delete(node->rightNode, temp->data, isDeleted);
    } else if (comparison > 0) {
        node->leftNode = delete(node->leftNode, data, isDeleted);
    } else {
        node->rightNode = delete(node->rightNode, data, isDeleted);
    }


    return node;
}

struct Node *store(struct Node *node, Data data, int *isStored) {
    if (node == NULL) {
        *isStored = 1;
        return createNewNode(data);
    }

    int checkIfStored = strcmp(node->data.name, data.name);
    if (checkIfStored == 0 && node->data.year == data.year && data.month == node->data.month &&
        node->data.day == data.day) {
        *isStored = 0;
        return node;
    }

    if (compare(node->data, data) > 0) {
        node->leftNode = store(node->leftNode, data, isStored);
    } else {
        node->rightNode = store(node->rightNode, data, isStored);
    }
    return node;
}

int find(struct Node *node, Data data) {
    if (node == NULL)
        return 0;

    int comparision = compare(node->data, data);

    if (comparision == 0)
        return 1;
    else if (comparision > 0)
        return find(node->leftNode, data);

    return find(node->rightNode, data);
}

int main() {
    Data data;
    struct Node *root = NULL;
    char typeSymbol;
    while (scanf(""%c: %d %d %d "", &typeSymbol, &data.year, &data.month, &data.day) != EOF) {
        data.name = scanWord(' ', malloc(sizeof(char)));
        if (typeSymbol == 'S') {
            int isStored;
            root = store(root, data, &isStored);
            if (isStored == 1) {
                printf(""Stored\n"");
            } else if (isStored == 0) {
                printf(""Already stored\n"");
            }
        } else if (typeSymbol == 'F') {
            if (find(root, data)) {
                printf(""Found\n"");
            } else {
                printf(""Not found\n"");
            }
        } else if (typeSymbol == 'D') {
            int isDeleted = 1;
            root = delete(root, data, &isDeleted);
            if (isDeleted == 1) {
                printf(""Deleted\n"");
            } else if (isDeleted == 0) {
                printf(""Not found\n"");
            }
        }
    }
    return 0;
}"
Database search,"#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Data {
    int year;
    int month;
    int day;
    char *name;
} Data;

struct Node {
    Data data;
    struct Node *leftNode;
    struct Node *rightNode;
};

struct Node *createNewNode(Data data) {
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    node->data = data;
    node->leftNode = NULL;
    node->rightNode = NULL;
    return node;
}

char *scanWord(char c, char *word) {
    int counter = 0;
    while (1) {
        scanf(""%c"", &c);
        if (c == '\n' || c == EOF) {
            return word;
        }
        word = realloc(word, counter + 1 * sizeof(char));
        word[counter++] = c;
        word[counter] = '\0';
    }
}

struct Node *findLowestValueNode(struct Node *node) {
    struct Node *currentNode = node;

    /* loop down to find the leftmost leaf */
    while (currentNode && currentNode->leftNode != NULL) {
        currentNode = currentNode->leftNode;
    }

    return currentNode;
}

int compare(Data currentNode, Data loadedData) {
    int stringCompare;
    if (currentNode.year == loadedData.year) {
        if (currentNode.month == loadedData.month) {
            if (currentNode.day == loadedData.day) {
                stringCompare = strcmp(currentNode.name, loadedData.name);
                if (stringCompare == 0) {
                    return 0;
                } else if (stringCompare == 1) {
                    return 1;
                } else {
                    return -1;
                }
            } else if (currentNode.day > loadedData.day) {
                return 1;
            } else {
                return -1;
            }
        } else if (currentNode.month > loadedData.month) {
            return 1;
        } else {
            return -1;
        }
    } else if (currentNode.year > loadedData.year) {
        return 1;
    } else {
        return -1;
    }
}

struct Node *delete(struct Node *node, Data data, int *isDeleted) {
    if (node == NULL) {
        *isDeleted = 0;
        return node;
    }

    int comparison = compare(node->data, data);

    if (comparison == 0) {
        if (node->leftNode == NULL) {
            struct Node *temp = node->rightNode;
            free(node->data.name);
            free(node);
            return temp;
        } else if (node->rightNode == NULL) {
            struct Node *temp = node->leftNode;
            free(node->data.name);
            free(node);
            return temp;
        }

        struct Node *temp = findLowestValueNode(node->rightNode);
        node->data = temp->data;
        node->rightNode = delete(node->rightNode, temp->data, isDeleted);
    } else if (comparison > 0) {
        node->leftNode = delete(node->leftNode, data, isDeleted);
    } else {
        node->rightNode = delete(node->rightNode, data, isDeleted);
    }


    return node;
}

struct Node *store(struct Node *node, Data data, int *isStored) {
    if (node == NULL) {
        *isStored = 1;
        return createNewNode(data);
    }

    int checkIfStored = strcmp(node->data.name, data.name);
    if (checkIfStored == 0 && node->data.year == data.year && data.month == node->data.month &&
        node->data.day == data.day) {
        *isStored = 0;
        return node;
    }

    if (compare(node->data, data) > 0) {
        node->leftNode = store(node->leftNode, data, isStored);
    } else {
        node->rightNode = store(node->rightNode, data, isStored);
    }
    return node;
}

int find(struct Node *node, Data data) {
    if (node == NULL)
        return 0;

    int comparision = compare(node->data, data);

    if (comparision == 0)
        return 1;
    else if (comparision > 0)
        return find(node->leftNode, data);

    return find(node->rightNode, data);
}

int main() {
    Data data;
    struct Node *root = NULL;
    char typeSymbol;
    while (scanf(""%c: %d %d %d "", &typeSymbol, &data.year, &data.month, &data.day) != EOF) {
        data.name = scanWord(' ', malloc(sizeof(char)));
        if (typeSymbol == 'S') {
            int isStored;
            root = store(root, data, &isStored);
            if (isStored == 1) {
                printf(""Stored\n"");
            } else if (isStored == 0) {
                printf(""Already stored\n"");
            }
            free(data.name);
        } else if (typeSymbol == 'F') {
            if (find(root, data)) {
                printf(""Found\n"");
            } else {
                printf(""Not found\n"");
            }
            free(data.name);
        } else if (typeSymbol == 'D') {
            int isDeleted = 1;
            root = delete(root, data, &isDeleted);
            if (isDeleted == 1) {
                printf(""Deleted\n"");
            } else if (isDeleted == 0) {
                printf(""Not found\n"");
            }
        }
    }
    return 0;
}"
Database search,"#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Data {
    int year;
    int month;
    int day;
    char *name;
} Data;

struct Node {
    Data data;
    struct Node *leftNode;
    struct Node *rightNode;
};

struct Node *createNewNode(Data data) {
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    node->data = data;
    node->leftNode = NULL;
    node->rightNode = NULL;
    return node;
}

char *scanWord(char c, char *word) {
    int counter = 0;
    while (1) {
        scanf(""%c"", &c);
        if (c == '\n' || c == EOF) {
            return word;
        }
        word = realloc(word, counter + 1 * sizeof(char));
        word[counter++] = c;
        word[counter] = '\0';
    }
}

struct Node *findLowestValueNode(struct Node *node) {
    struct Node *currentNode = node;

    /* loop down to find the leftmost leaf */
    while (currentNode && currentNode->leftNode != NULL) {
        currentNode = currentNode->leftNode;
    }

    return currentNode;
}

int compare(Data currentNode, Data loadedData) {
    int stringCompare;
    if (currentNode.year == loadedData.year) {
        if (currentNode.month == loadedData.month) {
            if (currentNode.day == loadedData.day) {
                stringCompare = strcmp(currentNode.name, loadedData.name);
                if (stringCompare == 0) {
                    return 0;
                } else if (stringCompare == 1) {
                    return 1;
                } else {
                    return -1;
                }
            } else if (currentNode.day > loadedData.day) {
                return 1;
            } else {
                return -1;
            }
        } else if (currentNode.month > loadedData.month) {
            return 1;
        } else {
            return -1;
        }
    } else if (currentNode.year > loadedData.year) {
        return 1;
    } else {
        return -1;
    }
}

struct Node *delete(struct Node *node, Data data, int *isDeleted) {
    if (node == NULL) {
        *isDeleted = 0;
        return node;
    }

    int comparison = compare(node->data, data);

    if (comparison == 0) {
        if (node->leftNode == NULL) {
            struct Node *temp = node->rightNode;
            free(node->data.name);
            free(node);
            return temp;
        } else if (node->rightNode == NULL) {
            struct Node *temp = node->leftNode;
            free(node->data.name);
            free(node);
            return temp;
        }

        struct Node *temp = findLowestValueNode(node->rightNode);
        node->data = temp->data;
        node->rightNode = delete(node->rightNode, temp->data, isDeleted);
    } else if (comparison > 0) {
        node->leftNode = delete(node->leftNode, data, isDeleted);
    } else {
        node->rightNode = delete(node->rightNode, data, isDeleted);
    }


    return node;
}

struct Node *store(struct Node *node, Data data, int *isStored) {
    if (node == NULL) {
        *isStored = 1;
        return createNewNode(data);
    }

    int checkIfStored = strcmp(node->data.name, data.name);
    if (checkIfStored == 0 && node->data.year == data.year && data.month == node->data.month &&
        node->data.day == data.day) {
        *isStored = 0;
        return node;
    }

    if (compare(node->data, data) > 0) {
        node->leftNode = store(node->leftNode, data, isStored);
    } else {
        node->rightNode = store(node->rightNode, data, isStored);
    }
    return node;
}

int find(struct Node *node, Data data) {
    if (node == NULL)
        return 0;

    int comparision = compare(node->data, data);

    if (comparision == 0)
        return 1;
    else if (comparision > 0)
        return find(node->leftNode, data);

    return find(node->rightNode, data);
}

int main() {
    Data data;
    struct Node *root = NULL;
    char typeSymbol;
    while (scanf(""%c: %d %d %d "", &typeSymbol, &data.year, &data.month, &data.day) != EOF) {
        data.name = scanWord(' ', malloc(sizeof(char)));
        if (typeSymbol == 'S') {
            int isStored;
            root = store(root, data, &isStored);
            if (isStored == 1) {
                printf(""Stored\n"");
            } else if (isStored == 0) {
                printf(""Already stored\n"");
            }
        } else if (typeSymbol == 'F') {
            if (find(root, data)) {
                printf(""Found\n"");
            } else {
                printf(""Not found\n"");
            }
            free(data.name);
        } else if (typeSymbol == 'D') {
            int isDeleted = 1;
            root = delete(root, data, &isDeleted);
            if (isDeleted == 1) {
                printf(""Deleted\n"");
            } else if (isDeleted == 0) {
                printf(""Not found\n"");
            }
        }
    }
    return 0;
}"
Database search,"#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Data {
    int year;
    int month;
    int day;
    char *name;
} Data;

struct Node {
    Data data;
    struct Node *leftNode;
    struct Node *rightNode;
};

struct Node *createNewNode(Data data) {
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    node->data = data;
    node->leftNode = NULL;
    node->rightNode = NULL;
    return node;
}

char *scanWord(char c, char *word) {
    int counter = 0;
    while (1) {
        scanf(""%c"", &c);
        if (c == '\n' || c == EOF) {
            return word;
        }
        word = realloc(word, counter + 1 * sizeof(char));
        word[counter++] = c;
        word[counter] = '\0';
    }
}

struct Node *findLowestValueNode(struct Node *node) {
    struct Node *currentNode = node;

    /* loop down to find the leftmost leaf */
    while (currentNode && currentNode->leftNode != NULL) {
        currentNode = currentNode->leftNode;
    }

    return currentNode;
}

int compare(Data currentNode, Data loadedData) {
    int stringCompare;
    if (currentNode.year == loadedData.year) {
        if (currentNode.month == loadedData.month) {
            if (currentNode.day == loadedData.day) {
                stringCompare = strcmp(currentNode.name, loadedData.name);
                if (stringCompare == 0) {
                    return 0;
                } else if (stringCompare == 1) {
                    return 1;
                } else {
                    return -1;
                }
            } else if (currentNode.day > loadedData.day) {
                return 1;
            } else {
                return -1;
            }
        } else if (currentNode.month > loadedData.month) {
            return 1;
        } else {
            return -1;
        }
    } else if (currentNode.year > loadedData.year) {
        return 1;
    } else {
        return -1;
    }
}

struct Node *delete(struct Node *node, Data data, int *isDeleted) {
    if (node == NULL) {
        *isDeleted = 0;
        return node;
    }

    int comparison = compare(node->data, data);

    if (comparison == 0) {
        if (node->leftNode == NULL) {
            struct Node *temp = node->rightNode;
            free(node->data.name);
            free(node);
            return temp;
        } else if (node->rightNode == NULL) {
            struct Node *temp = node->leftNode;
            free(node->data.name);
            free(node);
            return temp;
        }

        struct Node *temp = findLowestValueNode(node->rightNode);
        node->data = temp->data;
        node->rightNode = delete(node->rightNode, temp->data, isDeleted);
    } else if (comparison > 0) {
        node->leftNode = delete(node->leftNode, data, isDeleted);
    } else {
        node->rightNode = delete(node->rightNode, data, isDeleted);
    }

    return node;
}

struct Node *store(struct Node *node, Data data, int *isStored) {
    if (node == NULL) {
        *isStored = 1;
        return createNewNode(data);
    }

    int checkIfStored = strcmp(node->data.name, data.name);
    if (checkIfStored == 0 && node->data.year == data.year && data.month == node->data.month &&
        node->data.day == data.day) {
        *isStored = 0;
        return node;
    }

    if (compare(node->data, data) > 0) {
        node->leftNode = store(node->leftNode, data, isStored);
    } else {
        node->rightNode = store(node->rightNode, data, isStored);
    }
    return node;
}

int find(struct Node *node, Data data) {
    if (node == NULL)
        return 0;

    int comparision = compare(node->data, data);

    if (comparision == 0)
        return 1;
    else if (comparision > 0)
        return find(node->leftNode, data);

    return find(node->rightNode, data);
}

int main() {
    Data data;
    struct Node *root = NULL;
    char typeSymbol;
    while (scanf(""%c: %d %d %d "", &typeSymbol, &data.year, &data.month, &data.day) != EOF) {
        data.name = scanWord(' ', malloc(sizeof(char)));
        if (typeSymbol == 'S') {
            int isStored;
            root = store(root, data, &isStored);
            if (isStored == 1) {
                printf(""Stored\n"");
            } else if (isStored == 0) {
                printf(""Already stored\n"");
            }
        } else if (typeSymbol == 'F') {
            if (find(root, data)) {
                printf(""Found\n"");
            } else {
                printf(""Not found\n"");
            }
            free(data.name);
        } else if (typeSymbol == 'D') {
            int isDeleted = 1;
            root = delete(root, data, &isDeleted);
            if (isDeleted == 1) {
                printf(""Deleted\n"");
            } else if (isDeleted == 0) {
                printf(""Not found\n"");
            }
        }
    }
    return 0;
}"
Labyrint,"// The code below doesn't yet have bfs implemented. It simply creates two lists. Domjudge is a great versioning system. (I love wasting CPU cycles)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// TODO: find a way to pass different structs into the scan_stdin function. -> Done

struct Node {
	char data;
	struct Node *next;
};

struct Coordinates {
	char data;
	struct Node *next;
};

int scan_stdin(char, char, void *);

void push_into_list(struct Node *, char);

void print_list(struct Node *, int);

void show_runtime(clock_t);

int main() {
	clock_t begin = clock(); // better be small!!

	// LOAD THE MAZE AND PATHS

	struct Node *head = (struct Node *) malloc(sizeof(struct Node));
	struct Coordinates *coordinates_head = (struct Coordinates *) malloc(sizeof(struct Coordinates));
	int row_width = scan_stdin('#', '.', head);
	char scanNewLine;
	scanf(""%c"", &scanNewLine);
	int coordinates_width = scan_stdin('1', '2', coordinates_head);
	if (coordinates_width != row_width) {
		printf(""Widths do not match. Returning."");
		show_runtime(begin);
		return 0;
	}
	if (head->next == NULL) {
		printf(""List is empty\n"");
		show_runtime(begin);
		return 0;
	}
	print_list(head->next, row_width);
	printf(""\nrow width: %d\n"", row_width);

	// BFS (maybe)

	show_runtime(begin);
	return 0;
}

void bfs() {

}

int scan_stdin(char wall, char path, void *head) {
	int rowWidth = 0;
	int iteratedOverColumn = 0;
	int count = 0;
	char tmp;
	char *format = ""%c"";
	while (scanf(format, &tmp) != EOF) {
		if (iteratedOverColumn == 0) {
			if (tmp == wall || tmp == path) {
				count = count + 1;
			}
			if (tmp == '\n') {
				rowWidth = count;
				iteratedOverColumn = 1;
				format = "" %c"";
			}
		}

		if (tmp == '-') {
			break;
		}
		if (tmp == wall || tmp == path) {
			push_into_list(head, tmp);
		}
	}
	return rowWidth;
}

//	Formát lze popsat takto: <index řádku startovnáho bodu> <index
//	sloupce startovního bodu> <index řádku koncového bodu> <index
//	sloupce koncového bodu>

void show_runtime(clock_t begin) {
	clock_t end = clock();
	double time_spent = (double) (end - begin);
	printf(""\n\nruntime: %fs\n"", time_spent / CLOCKS_PER_SEC);
}

void push_into_list(struct Node *node, char data) {
	while (node->next != NULL) {
		node = node->next;
	}

	node->next = (struct Node *) malloc(sizeof(struct Node));
	node->next->data = data;
	node->next->next = NULL;
}

void print_list(struct Node *node, int rowWidth) {
	int count = 1;
	while (node != NULL) {
		printf(""%c"", node->data);
		if (count % rowWidth == 0) {
			printf(""\n"");
		}
		node = node->next;
		count = count + 1;
	}
}
"
Labyrint,"#include <stdio.h>
#include <stdlib.h>

struct Node {
	int vertex;
	struct Node *next;
};

struct Path {
	int start;
	int end;
};

struct Queue_Node {
	int data;
	struct Queue_Node *next;
};

struct Queue {
	struct Queue_Node *front;
	struct Queue_Node *rear;
};

struct Queue *create_queue();

int is_empty(struct Queue *);

void enqueue(struct Queue *, int);

int dequeue(struct Queue *);

void create_node(int data, struct Node **graph);

struct Node *get_adjacency(int, char *, int, int);

char *load_labyrinth(int *, int *);

int left(int, int, const char *);

int right(int, int, const char *);

int up(int, int, const char *);

int down(int, int, int, const char *);

void find_end(struct Queue *, struct Node *[], int[], struct Path, int *);

void robot_logic(int, int, struct Node *[], struct Path);

int main() {
	// scanning the first part of the input
	int verticies, column = 0;
	char *buffer = load_labyrinth(&verticies, &column);

	struct Path coordinate;

	struct Node *graph[verticies + 1];

	for (int i = 0; i < verticies; ++i) {
		if (buffer[i] == '#')
			continue;

		graph[i] = get_adjacency(i, buffer, column, verticies + 1);
	}

	// logic concerning the second part of the input
	robot_logic(verticies, column, graph, coordinate);

	return 0;

}

void find_end(struct Queue *queue, struct Node *graph[], int distance[], struct Path coordinate, int *isFound) {
	while (!is_empty(queue)) {
		int front_item = dequeue(queue);
		struct Node *adjacency = graph[front_item];

		while (adjacency != NULL) {
			int neighbor = adjacency->vertex;
			if (distance[neighbor] == -1) {
				distance[neighbor] = distance[front_item] + 1;
				enqueue(queue, neighbor);
				if (adjacency->vertex == coordinate.end) {
					printf(""%d\n"", distance[adjacency->vertex] + 1);
					*isFound = 1;
					break;
				}
			}

			adjacency = adjacency->next;

		}
		if (*isFound)
			break;
	}
}

void robot_logic(int verticies, int column, struct Node *graph[], struct Path coordinate) {
	while (1) {
		int startRow, startColumn, endRow, endColumn;
		if (scanf(""%d %d %d %d"", &startRow, &startColumn, &endRow, &endColumn) == EOF) {
			break;
		}

		if (startRow * column + startColumn == endRow * column + endColumn) {
			printf(""%d\n"", 0);
			continue;
		}

		coordinate.start = startRow * column + startColumn;
		coordinate.end = endRow * column + endColumn;

		struct Queue *queue = create_queue();

		int visited[verticies + 1];
		int distance[verticies + 1];

		for (int i = 0; i < verticies + 1; i++) {
			distance[i] = -1;
		}

		for (int i = 0; i <= verticies + 1; i++) {
			visited[i] = 0;
		}

		visited[coordinate.start] = 1;
		enqueue(queue, coordinate.start);

		int isFound = 0;
		find_end(queue, graph, distance, coordinate, &isFound);
		if (!isFound)
			printf(""%d\n"", -1);


	}
}


char *load_labyrinth(int *index, int *column) {
	int i;
	int col;
	char *buffer = NULL;
	while (1) {
		char input = getc(stdin);
		if (input == ' ')
			continue;
		if (input == '\n') {
			col = i;
			break;
		}

		i++;
		buffer = realloc(buffer, i);
		buffer[i] = input;
	}

	buffer = realloc(buffer, i + 1);
	buffer[i + 1] = '\0';

	char input;
	while (1) {
		scanf("" %c"", &input);
		if (input == '-') {
			break;
		}

		buffer = realloc(buffer, i + 2);
		buffer[i++] = input;
		buffer[i] = '\0';
	}
	*index = i;
	*column = col;
	return buffer;
}

struct Queue *create_queue() {
	struct Queue *queue = (struct Queue *) malloc(sizeof(struct Queue));
	queue->front = queue->rear = NULL;
	return queue;
}


int is_empty(struct Queue *queue) {
	return (queue->front == NULL);
}


void enqueue(struct Queue *queue, int data) {
	struct Queue_Node *temp = (struct Queue_Node *) malloc(sizeof(struct Queue_Node));
	temp->data = data;
	temp->next = NULL;
	if (queue->rear == NULL) {
		queue->front = queue->rear = temp;
		return;
	}

	queue->rear->next = temp;
	queue->rear = temp;
}


int dequeue(struct Queue *queue) {
	if (is_empty(queue))
		return -1;
	struct Queue_Node *temp = queue->front;
	int item = temp->data;
	queue->front = temp->next;
	if (queue->front == NULL)
		queue->rear = NULL;
	free(temp);
	return item;
}

void create_node(int data, struct Node **graph) {
	struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
	newNode->vertex = data;
	newNode->next = *graph;
	*graph = newNode;
}

struct Node *get_adjacency(int i, char *buffer, int col, int total) {
	struct Node *temp = NULL;

	int l = left(i, col, buffer);
	int r = right(i, col, buffer);
	int u = up(i, col, buffer);
	int d = down(i, col, total / col, buffer);

	if (d != -1)
		create_node(d, &temp);
	if (r != -1)
		create_node(r, &temp);
	if (l != -1)
		create_node(l, &temp);
	if (u != -1)
		create_node(u, &temp);

	return temp;
}

int left(int k, int col, const char *buffer) {
	if (k % col == 0)
		return -1;
	if (buffer[k - 1] != '.')
		return -1;
	return k - 1;
}

int right(int k, int col, const char *buffer) {
	if (k % col == col - 1)
		return -1;
	if (buffer[k + 1] != '.')
		return -1;
	return k + 1;
}

int up(int k, int col, const char *buffer) {
	if (k - col < 0)
		return -1;
	if (buffer[k - col] != '.')
		return -1;
	return k - col;
}

int down(int k, int col, int row, const char *buffer) {
	if (k + col > row * col - 1)
		return -1;
	if (buffer[k + col] != '.')
		return -1;
	return k + col;
}"
Labyrint,"#include <stdio.h>
#include <stdlib.h>

struct Node {
	int vertex;
	struct Node *next;
};

struct Path {
	int start;
	int end;
};

struct Queue_Node {
	int data;
	struct Queue_Node *next;
};

struct Queue {
	struct Queue_Node *front;
	struct Queue_Node *rear;
};

struct Queue *create_queue();

int is_empty(struct Queue *);

void enqueue(struct Queue *, int);

int dequeue(struct Queue *);

void create_node(int data, struct Node **graph);

struct Node *get_adjacency(int, char *, int, int);

char *load_labyrinth(int *, int *);

int left(int, int, const char *);

int right(int, int, const char *);

int up(int, int, const char *);

int down(int, int, int, const char *);

void find_end(struct Queue *, struct Node *[], int[], struct Path, int *);

void robot_logic(int, int, struct Node *[], struct Path);

int main() {
	// scanning the first part of the input
	int verticies, column = 0;
	char *buffer = load_labyrinth(&verticies, &column);

	struct Path coordinate;

	struct Node *graph[verticies + 1];

	for (int i = 0; i < verticies + 1; i++) {
		graph[i] = NULL;
	}

	for (int i = 0; i < verticies; ++i) {
		if (buffer[i] == '#')
			continue;

		graph[i] = get_adjacency(i, buffer, column, verticies + 1);
	}

	// logic concerning the second part of the input
	robot_logic(verticies, column, graph, coordinate);

	return 0;

}

void find_end(struct Queue *queue, struct Node *graph[], int distance[], struct Path coordinate, int *isFound) {
	while (!is_empty(queue)) {
		int front_item = dequeue(queue);
		struct Node *adjacency = graph[front_item];

		while (adjacency != NULL) {
			int neighbor = adjacency->vertex;
			if (distance[neighbor] == -1) {
				distance[neighbor] = distance[front_item] + 1;
				enqueue(queue, neighbor);
				if (adjacency->vertex == coordinate.end) {
					printf(""%d\n"", distance[adjacency->vertex] + 1);
					*isFound = 1;
					break;
				}
			}

			adjacency = adjacency->next;

		}
		if (*isFound)
			break;
	}
}

void robot_logic(int verticies, int column, struct Node *graph[], struct Path coordinate) {
	while (1) {
		int startRow, startColumn, endRow, endColumn;
		if (scanf(""%d %d %d %d"", &startRow, &startColumn, &endRow, &endColumn) == EOF) {
			break;
		}

		if (startRow * column + startColumn == endRow * column + endColumn) {
			printf(""%d\n"", 0);
			continue;
		}

		coordinate.start = startRow * column + startColumn;
		coordinate.end = endRow * column + endColumn;

		struct Queue *queue = create_queue();

		int distance[verticies + 1];

		for (int i = 0; i < verticies + 1; i++) {
			distance[i] = -1;
		}

		for (int i = 0; i <= verticies + 1; i++) {
		}

		enqueue(queue, coordinate.start);

		int isFound = 0;
		find_end(queue, graph, distance, coordinate, &isFound);
		if (!isFound)
			printf(""%d\n"", -1);
	}
}


char *load_labyrinth(int *index, int *column) {
	int i = 0;
	int col;
	char *buffer = NULL;
	while (1) {
		char input = getc(stdin);
		if (input == ' ')
			continue;
		if (input == '\n') {
			col = i;
			break;
		}

		i++;
		buffer = realloc(buffer, i);
		buffer[i] = input;
	}

	buffer = realloc(buffer, i + 1);
	buffer[i + 1] = '\0';

	char input;
	while (1) {
		scanf("" %c"", &input);
		if (input == '-') {
			break;
		}

		buffer = realloc(buffer, i + 2);
		buffer[i++] = input;
		buffer[i] = '\0';
	}
	*index = i;
	*column = col;
	return buffer;
}

struct Queue *create_queue() {
	struct Queue *queue = (struct Queue *) malloc(sizeof(struct Queue));
	queue->front = queue->rear = NULL;
	return queue;
}


int is_empty(struct Queue *queue) {
	return (queue->front == NULL);
}


void enqueue(struct Queue *queue, int data) {
	struct Queue_Node *temp = (struct Queue_Node *) malloc(sizeof(struct Queue_Node));
	temp->data = data;
	temp->next = NULL;
	if (queue->rear == NULL) {
		queue->front = queue->rear = temp;
		return;
	}

	queue->rear->next = temp;
	queue->rear = temp;
}


int dequeue(struct Queue *queue) {
	if (is_empty(queue))
		return -1;
	struct Queue_Node *temp = queue->front;
	int item = temp->data;
	queue->front = temp->next;
	if (queue->front == NULL)
		queue->rear = NULL;
	free(temp);
	return item;
}

void create_node(int data, struct Node **graph) {
	struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
	newNode->vertex = data;
	newNode->next = *graph;
	*graph = newNode;
}

struct Node *get_adjacency(int i, char *buffer, int col, int total) {
	struct Node *temp = NULL;

	int l = left(i, col, buffer);
	int r = right(i, col, buffer);
	int u = up(i, col, buffer);
	int d = down(i, col, total / col, buffer);

	if (d != -1)
		create_node(d, &temp);
	if (r != -1)
		create_node(r, &temp);
	if (l != -1)
		create_node(l, &temp);
	if (u != -1)
		create_node(u, &temp);

	return temp;
}

int left(int k, int col, const char *buffer) {
	if (k % col == 0)
		return -1;
	if (buffer[k - 1] != '.')
		return -1;
	return k - 1;
}

int right(int k, int col, const char *buffer) {
	if (k % col == col - 1)
		return -1;
	if (buffer[k + 1] != '.')
		return -1;
	return k + 1;
}

int up(int k, int col, const char *buffer) {
	if (k - col < 0)
		return -1;
	if (buffer[k - col] != '.')
		return -1;
	return k - col;
}

int down(int k, int col, int row, const char *buffer) {
	if (k + col > row * col - 1)
		return -1;
	if (buffer[k + col] != '.')
		return -1;
	return k + col;
}"
Labyrint,"#include <stdio.h>
#include <stdlib.h>

struct Node {
	int vertex;
	struct Node *next;
};

struct Path {
	int start;
	int end;
};

struct Queue_Node {
	int data;
	struct Queue_Node *next;
};

struct Queue {
	struct Queue_Node *front;
	struct Queue_Node *rear;
};

struct Queue *create_queue();

int is_empty(struct Queue *);

void enqueue(struct Queue *, int);

int dequeue(struct Queue *);

void create_node(int data, struct Node **graph);

struct Node *get_adjacency(int, char *, int, int);

char *load_labyrinth(int *, int *);

int left(int, int, const char *);

int right(int, int, const char *);

int up(int, int, const char *);

int down(int, int, int, const char *);

void find_end(struct Queue *, struct Node *[], int[], struct Path, int *);

void robot_logic(int, int, struct Node *[], struct Path);

int main() {
	// scanning the first part of the input
	int verticies, column = 0;
	char *buffer = load_labyrinth(&verticies, &column);

	struct Path coordinate;

	struct Node **graph = malloc((verticies + 1) * sizeof(struct Node*));
	if (graph == NULL) {
		fputs(""Failed to allocate memory! !! !! !!!\n"", stderr);
		return 1;
	}

	for (int i = 0; i < verticies; i++) {
		graph[i] = malloc(sizeof (struct Node*));
		graph[i] = NULL;
	}

	for (int i = 0; i < verticies; ++i) {
		if (buffer[i] == '#')
			continue;

		graph[i] = get_adjacency(i, buffer, column, verticies + 1);
	}

	// logic concerning the second part of the input
	robot_logic(verticies, column, graph, coordinate);

	return 0;

}

void find_end(struct Queue *queue, struct Node *graph[], int distance[], struct Path coordinate, int *isFound) {
	while (!is_empty(queue)) {
		int front_item = dequeue(queue);
		struct Node *adjacency = graph[front_item];

		while (adjacency != NULL) {
			int neighbor = adjacency->vertex;
			if (distance[neighbor] == -1) {
				distance[neighbor] = distance[front_item] + 1;
				enqueue(queue, neighbor);
				if (adjacency->vertex == coordinate.end) {
					printf(""%d\n"", distance[adjacency->vertex] + 1);
					*isFound = 1;
					break;
				}
			}

			adjacency = adjacency->next;

		}
		if (*isFound)
			break;
	}
}

void robot_logic(int verticies, int column, struct Node *graph[], struct Path coordinate) {
	while (1) {
		int startRow, startColumn, endRow, endColumn;
		if (scanf(""%d %d %d %d"", &startRow, &startColumn, &endRow, &endColumn) == EOF) {
			break;
		}

		if (startRow * column + startColumn == endRow * column + endColumn) {
			printf(""%d\n"", 0);
			continue;
		}

		coordinate.start = startRow * column + startColumn;
		coordinate.end = endRow * column + endColumn;

		struct Queue *queue = create_queue();

		int distance[verticies + 1];

		for (int i = 0; i < verticies + 1; i++) {
			distance[i] = -1;
		}

		for (int i = 0; i <= verticies + 1; i++) {
		}

		enqueue(queue, coordinate.start);

		int isFound = 0;
		find_end(queue, graph, distance, coordinate, &isFound);
		if (!isFound)
			printf(""%d\n"", -1);
	}
}


char *load_labyrinth(int *index, int *column) {
	int i = 0;
	int col;
	char *buffer = NULL;
	while (1) {
		char input = getc(stdin);
		if (input == ' ')
			continue;
		if (input == '\n') {
			col = i;
			break;
		}

		i++;
		buffer = realloc(buffer, i + 1);
		buffer[i] = input;
	}

	buffer = realloc(buffer, i + 1);
	buffer[i] = '\0';

	char input;
	while (1) {
		scanf("" %c"", &input);
		if (input == '-') {
			break;
		}

		buffer = realloc(buffer, i + 2);
		buffer[i++] = input;
		buffer[i] = '\0';
	}
	*index = i;
	*column = col;
	return buffer;
}

struct Queue *create_queue() {
	struct Queue *queue = (struct Queue *) malloc(sizeof(struct Queue));
	queue->front = queue->rear = NULL;
	return queue;
}


int is_empty(struct Queue *queue) {
	return (queue->front == NULL);
}


void enqueue(struct Queue *queue, int data) {
	struct Queue_Node *temp = (struct Queue_Node *) malloc(sizeof(struct Queue_Node));
	temp->data = data;
	temp->next = NULL;
	if (queue->rear == NULL) {
		queue->front = queue->rear = temp;
		return;
	}

	queue->rear->next = temp;
	queue->rear = temp;
}


int dequeue(struct Queue *queue) {
	if (is_empty(queue))
		return -1;
	struct Queue_Node *temp = queue->front;
	int item = temp->data;
	queue->front = temp->next;
	if (queue->front == NULL)
		queue->rear = NULL;
	free(temp);
	return item;
}

void create_node(int data, struct Node **graph) {
	struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
	newNode->vertex = data;
	newNode->next = *graph;
	*graph = newNode;
}

struct Node *get_adjacency(int i, char *buffer, int col, int total) {
	struct Node *temp = NULL;

	int l = left(i, col, buffer);
	int r = right(i, col, buffer);
	int u = up(i, col, buffer);
	int d = down(i, col, total / col, buffer);

	if (d != -1)
		create_node(d, &temp);
	if (r != -1)
		create_node(r, &temp);
	if (l != -1)
		create_node(l, &temp);
	if (u != -1)
		create_node(u, &temp);

	return temp;
}

int left(int k, int col, const char *buffer) {
	if (k % col == 0)
		return -1;
	if (buffer[k - 1] != '.')
		return -1;
	return k - 1;
}

int right(int k, int col, const char *buffer) {
	if (k % col == col - 1)
		return -1;
	if (buffer[k + 1] != '.')
		return -1;
	return k + 1;
}

int up(int k, int col, const char *buffer) {
	if (k - col < 0)
		return -1;
	if (buffer[k - col] != '.')
		return -1;
	return k - col;
}

int down(int k, int col, int row, const char *buffer) {
	if (k + col > row * col - 1)
		return -1;
	if (buffer[k + col] != '.')
		return -1;
	return k + col;
}"
