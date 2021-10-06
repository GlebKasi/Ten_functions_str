
#define UI unsigned int
#define null 0

int putsi(const char* str)
{
    UI index = 0;
    while ( str[index] != '\0' )
    {
        printf("%c", str[index]);
        index++;
    }
    if( index == 0 )
    {
        return EOF;
    }
    else
    {
        return '\n';
    }
}

char* strchri(char* str, int ch)
{
    UI index = 0;
    while (( str[index] != ch ) && (str[index] != '\0'))
    {
        index++;
    }
    if(str[index] == ch)
    {
        return index + str;
    }
    else
    {
        return NULL;
    }
}

size_t strleni(const char* str)
{
    size_t index = 0;
    while( str[index] != '\0' )
    {
        index++;
    }
    return index;
}

char* strcpyi(char* str1, const char* str2)
{
    UI index = 0;
    while( str2[index] != '\0' )
    {
        str1[index] = str2[index];
    }
    return str1;
}

char* strncpyi(char* str1, const char* str2, size_t num)
{
    UI index = 0;
    UI over = 0;
    while( index < num )
    {
        if(over == 0)
        {
            str1[index] = str2[index];
        }
        else
        {
            str1[index] = '\0';
        }
        if(str2[index] == '\0')
        {
            over = 1;
        }
    }
    return str1;
}

char* strcati(char* str1, const char* str2)
{
    UI index = 0;
    UI size_str1 = strleni(str1);
    while(str2[index] != '\0')
    {
        str1[size_str1+index]=str2[index];
        index++;
    }
    str1[size_str1+index] = '\0';
    return str1;
}

char* strncati(char* str1, const char* str2, size_t num)
{
    UI index = 0;
    UI size_str1 = strleni(str1);
    while((index < num) && (str2[index] != '\0'))
    {
        str1[size_str1+index]=str2[index];
        index++;
    }
    str1[size_str1+index] = '\0';
    return str1;
}

char* fgetsi(char* str, int num, FILE* stream)
{
    int index = 0;
    int sym = 0;
    while ((index < num) && (!feof(stream)) && ((sym = getc(stream))!='\n'))
    {
        str[index] = '\0'+sym;
        index++;
    }
    return str;
}

char* strdupi(const char* str)
{
    UI index = 0;
    char* str_copy = (char*) malloc(strleni(str)+1);
    while(str[index] != '\0')
    {
        str_copy[index] = str[index];
        index++;
    }
    str_copy[index] = '\0';
    return str_copy;
}

size_t getlinei(char** lineptr, size_t* n, FILE* stream)
{
    UI index = 0;
    char sym = 0;
    if ( *lineptr == nullptr )
    {
        char lineptrnew;
        *lineptr = &lineptrnew;
    }
    if( *n == null )
    {
        *lineptr = (char*) malloc((size_t) index + 1);
        **lineptr = '\0';
        while((!feof(stream)) && ((sym = (char) getc(stream)) != '\n'))
        {
            index ++;
            *lineptr = (char*) realloc((void*) (*lineptr) ,(size_t) index + 1);
            assert(*lineptr != nullptr);
            *(*lineptr + index) = '\0';
            *(*lineptr + index - 1) = sym;
        }
        if(sym == '\n')
        {
            index ++;
            *lineptr = (char*) realloc((void*) (*lineptr) ,(size_t) index + 1);
            assert(*lineptr != nullptr);
            *(*lineptr + index) = '\0';
            *(*lineptr + index - 1) = '\n';
        }
    }
    else
    {
        *lineptr = (char*) malloc((size_t) *n + 1);
        *(*lineptr + (UI) *n) = '\0';
        while((!feof(stream)) && ((sym = (char) getc(stream)) != '\n'))
        {
            *(*lineptr + index) = sym;
            index++;
            *(*lineptr + index) = '\0';
            if(index == (UI) *n)
            {
                break;
            }
        }
        if((sym == '\n') && (index < (UI) *n))
        {
            *(*lineptr + index) = '\n';
            *(*lineptr + index + 1) = '\0';
        }
    }
}
