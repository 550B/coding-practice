/*2151974 软件 赵明泽*/
//#include <iostream>
//using namespace std;
/* 函数实现部分，{ }内的东西可以任意调整，目前的return 0只是一个示例，可改变 */

/* 不允许定义任何形式的外部全局、静态全局、宏定义、只读变量 */

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strlen(const char str[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int cnt = 0;
    while (str[cnt] != '\0')
    {
        cnt++;
    }

    return cnt; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcat(char s1[], const char s2[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int cnt = 0;
    while (s1[cnt] != '\0')
    {
        cnt++;
    }
    int i = 0;
    while (s2[i] != '\0')
    {
        s1[cnt] = s2[i];
        cnt++;
        i++;
    }
    s1[cnt] = '\0';

    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strncat(char s1[], const char s2[], const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int m = len;
    if (tj_strlen(s2) + 1 < len)
    {
        m = tj_strlen(s2) + 1;
    }
    int cnt = 0;
    while (s1[cnt] != '\0')
    {
        cnt++;
    }
    int i = 0;
    while (i != m)
    {
        s1[cnt] = s2[i];
        cnt++;
        i++;
    }
    s1[cnt] = '\0';

    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcpy(char s1[], const char s2[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int cnt = 0;
    while (s2[cnt] != '\0')
    {
        s1[cnt] = s2[cnt];
        cnt++;
    }
    s1[cnt] = '\0';

    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strncpy(char s1[], const char s2[], const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int m = len;
    if (tj_strlen(s2) < len)
    {
        m = tj_strlen(s2);
    }
    int cnt = 0;
    while (cnt != m)
    {
        s1[cnt] = s2[cnt];
        cnt++;
    }

    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcmp(const char s1[], const char s2[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int dfc;
    int cnt = 0;
    while (s1[cnt] != '\0' && s2[cnt] != '\0')
    {
        if (s1[cnt] == s2[cnt])
        {
            cnt++;
            continue;
        }
        else
        {
            dfc = s1[cnt] - s2[cnt];
            return dfc;
        }
    }
    if (s1[cnt] == '\0' && s2[cnt] != '\0')
    {
        dfc = 0 - s2[cnt];
    }
    else if (s1[cnt] != '\0' && s2[cnt] == '\0')
    {
        dfc = s1[cnt];
    }
    else
    {
        dfc = 0;
    }

    return dfc; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcasecmp(const char s1[], const char s2[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int dfc;
    int cnt = 0;
    while (s1[cnt] != '\0' && s2[cnt] != '\0')
    {
        if (((s1[cnt] >= 'a' && s1[cnt] <= 'z' && s2[cnt] >= 'a' && s2[cnt] <= 'z') ||
             (s1[cnt] >= 'A' && s1[cnt] <= 'Z' && s2[cnt] >= 'A' && s2[cnt] <= 'Z') ||
             (s1[cnt] >= 'a' && s1[cnt] <= 'z' && s2[cnt] >= 'A' && s2[cnt] <= 'Z') ||
             (s1[cnt] >= 'A' && s1[cnt] <= 'Z' && s2[cnt] >= 'a' && s2[cnt] <= 'z')) && (
              s1[cnt]==s2[cnt] || s1[cnt] - s2[cnt] == 'a' - 'A' || s2[cnt] - s1[cnt] == 'a' - 'A'))
        {
            cnt++;
            continue;
        }
        else if (s1[cnt] == s2[cnt])
        {
            cnt++;
            continue;
        }
        else
        {
            if (s1[cnt] >= 'A' && s1[cnt] <= 'Z')
            {
                if (s2[cnt] >= 'A' && s2[cnt] <= 'Z')
                {
                    dfc = s1[cnt] - s2[cnt];
                    return dfc;
                }
                else
                {
                    dfc = s1[cnt] - s2[cnt] + 'a' - 'A';
                    return dfc;
                }
            }
            else
            {
                if (s2[cnt] >= 'A' && s2[cnt] <= 'Z')
                {
                    dfc = s1[cnt] - s2[cnt] - 'a' + 'A';
                    return dfc;
                }
                else
                {
                    dfc = s1[cnt] - s2[cnt];
                    return dfc;
                }
            }
        }
    }
    if (s1[cnt] == '\0' && s2[cnt] != '\0')
    {
        if (s2[cnt] >= 'A' && s2[cnt] <= 'Z')
        {
            dfc = 0 - s2[cnt] - 'a' + 'A';
            return dfc;
        }
        else
        {
            dfc = 0 - s2[cnt];
            return dfc;
        }
    }
    else if (s1[cnt] != '\0' && s2[cnt] == '\0')
    {
        if (s1[cnt] >= 'A' && s1[cnt] <= 'Z')
        {
            dfc = s1[cnt] + 'a' - 'A';
            return dfc;
        }
        else
        {
            dfc = s1[cnt];
            return dfc;
        }
    }
    else
    {
        dfc = 0;
    }

    return dfc; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strncmp(const char s1[], const char s2[], const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int dfc;
    int cnt = 0;
    int m = len;
    if ((tj_strlen(s2) + 1 > tj_strlen(s1) + 1 ? tj_strlen(s1) + 1 : tj_strlen(s2) + 1) < len)
    {
        m = (tj_strlen(s2) + 1 > tj_strlen(s1) + 1 ? tj_strlen(s1) + 1 : tj_strlen(s2) + 1);
    }
    int i = 0;
    while (i != m)
    {
        if (s1[cnt] == s2[cnt])
        {
            cnt++;
            i++;
            continue;
        }
        else
        {
            dfc = s1[cnt] - s2[cnt];
            return dfc;
        }
    }
    if (s1[cnt - 1] == '\0' && s2[cnt - 1] != '\0')
    {
        dfc = 0 - s2[cnt - 1];
    }
    else if (s1[cnt - 1] != '\0' && s2[cnt - 1] == '\0')
    {
        dfc = s1[cnt - 1];
    }
    else
    {
        dfc = 0;
    }

    return dfc; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcasencmp(const char s1[], const char s2[], const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int dfc;
    int cnt = 0;
    int m = len;
    if ((tj_strlen(s2) + 1 > tj_strlen(s1) + 1 ? tj_strlen(s1) + 1 : tj_strlen(s2) + 1) < len)
    {
        m = (tj_strlen(s2) + 1 > tj_strlen(s1) + 1 ? tj_strlen(s1) + 1 : tj_strlen(s2) + 1);
    }
    int i = 0;
    while (/*s1[cnt] != '\0' && s2[cnt] != '\0'*/i != m)
    {
        if (((s1[cnt] >= 'a' && s1[cnt] <= 'z' && s2[cnt] >= 'a' && s2[cnt] <= 'z') ||
            (s1[cnt] >= 'A' && s1[cnt] <= 'Z' && s2[cnt] >= 'A' && s2[cnt] <= 'Z') ||
            (s1[cnt] >= 'a' && s1[cnt] <= 'z' && s2[cnt] >= 'A' && s2[cnt] <= 'Z') ||
            (s1[cnt] >= 'A' && s1[cnt] <= 'Z' && s2[cnt] >= 'a' && s2[cnt] <= 'z')) && (
                s1[cnt] == s2[cnt] || s1[cnt] - s2[cnt] == 'a' - 'A' || s2[cnt] - s1[cnt] == 'a' - 'A'))
        {
            cnt++;
            i++;
            continue;
        }
        else if (s1[cnt] == s2[cnt])
        {
            cnt++;
            i++;
            continue;
        }
        else
        {
            if (s1[cnt] >= 'A' && s1[cnt] <= 'Z')
            {
                if (s2[cnt] >= 'A' && s2[cnt] <= 'Z')
                {
                    dfc = s1[cnt] - s2[cnt];
                    return dfc;
                }
                else
                {
                    dfc = s1[cnt] - s2[cnt] + 'a' - 'A';
                    return dfc;
                }
            }
            else
            {
                if (s2[cnt] >= 'A' && s2[cnt] <= 'Z')
                {
                    dfc = s1[cnt] - s2[cnt] - 'a' + 'A';
                    return dfc;
                }
                else
                {
                    dfc = s1[cnt] - s2[cnt];
                    return dfc;
                }
            }
        }
    }
    if (s1[cnt-1] == '\0' && s2[cnt-1] != '\0')
    {
        if (s2[cnt-1] >= 'A' && s2[cnt-1] <= 'Z')
        {
            dfc = 0 - s2[cnt-1] - 'a' + 'A';
            return dfc;
        }
        else
        {
            dfc = 0 - s2[cnt-1];
            return dfc;
        }
    }
    else if (s1[cnt-1] != '\0' && s2[cnt-1] == '\0')
    {
        if (s1[cnt-1] >= 'A' && s1[cnt-1] <= 'Z')
        {
            dfc = s1[cnt-1] + 'a' - 'A';
            return dfc;
        }
        else
        {
            dfc = s1[cnt-1];
            return dfc;
        }
    }
    else
    {
        dfc = 0;
    }

    return dfc; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strupr(char str[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int cnt = 0;
    while (str[cnt] != '\0')
    {
        if (str[cnt] >= 'a' && str[cnt] <= 'z')
        {
            str[cnt] = (char)(str[cnt] - 'a' + 'A');
            cnt++;
        }
        else
        {
            cnt++;
            continue;
        }
    }

    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strlwr(char str[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int cnt = 0;
    while (str[cnt] != '\0')
    {
        if (str[cnt] >= 'A' && str[cnt] <= 'Z')
        {
            str[cnt] = (char)(str[cnt] + 'a' - 'A');
            cnt++;
        }
        else
        {
            cnt++;
            continue;
        }
    }

    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strchr(const char str[], char ch)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int cnt = 0;
    while (str[cnt] != '\0')
    {
        if (str[cnt] == ch)
        {
            return ++cnt;
        }
        else
        {
            cnt++;
            continue;
        }
    }

    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strstr(const char str[], const char substr[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int a = tj_strlen(str);
    int b = tj_strlen(substr);
    int i = 0, j = 0;
    while (i < a && j < b )
    {
        if (str[i] == substr[j])
        {
            i++;
            j++;
        }
        else
        {
            i = i - j + 1;
            j = 0;
        }
    }
    if (j == b )
    {
        return i - j + 1;
    }

    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strrchr(const char str[], const char ch)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int cnt = tj_strlen(str) - 1;
    while (cnt != -1)
    {
        if (str[cnt] == ch)
        {
            return ++cnt;
        }
        else
        {
            cnt--;
            continue;
        }
    }

    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strrstr(const char str[], const char substr[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int a = tj_strlen(str) - 1;
    int b = tj_strlen(substr) - 1;
    int i = a, j = b;
    while (i >= 0 && j >= 0)
    {
        if (str[i] == substr[j])
        {
            i--;
            j--;
        }
        else
        {
            i = i + b - j - 1;
            j = b;
        }
    }
    if (j == -1)
    {
        return i + 2;
    }

    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strrev(char str[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int head = 0;
    int end = tj_strlen(str) - 1;
    while (head <= end)
    {
        char tmp = str[end];
        str[end] = str[head];
        str[head] = tmp;
        head++;
        end--;
    }

    return 0; //return值可根据需要修改
}
