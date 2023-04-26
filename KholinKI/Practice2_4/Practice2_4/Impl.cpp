#include "TContainer.h"

template <class TELEM>
TContainer<TELEM>::TContainer(void) {
    size = 0;
    count_elements = 0;
    TELEM* elements = nullptr;
}

template <class TELEM>
TContainer<TELEM>::TContainer(int _size) : size(_size), count(0)

{
    elements = new TELEM[size];
}

//------------------------------------------------------------------------------------ 

template <class TELEM>
TContainer<TELEM>::TContainer(const TContainer<TELEM>& obj)

{
    size = obj.size;
    count = obj.count_elements;
    elements = new TELEM[size];
    for (int i = 0; i < count_elements; i++)
        elements[i] = obj.elements[i];
}

//------------------------------------------------------------------------------------ 

template <class TELEM>
TContainer<TELEM>::~TContainer()

{
    if (size > 0) {
        delete[] elem;
        elem = 0;
        count = 0;
        size = 0;
    }

}


template <class TELEM>
void TContainer<TELEM>::realloc(int dsize)  // increase length massive

{
    //dsize - size by which to increase
    if (dsize == 0) dsize = sizestep;
    size += dsize;
    TELEM* tmp = new TELEM[size];//changed array
    for (int i = 0; i < count; i++)
        tmp[i] = elements[i];
    delete[] elements;
    elements = tmp;
}

template <class TELEM>
TContainer<TELEM>& TContainer<TELEM>::operator=(const TContainer<TELEM>& obj)//object assignment

{
    if (this != &obj) {//avoid dublicate object
        delete[] elem;;
        size = obj.size;
        count_elements = obj.count_elements;
        elements = new TELEM[size];
        for (int i = 0; i < count_elements; i++)
            elem[i] = obj.elem[i];
    }
    return *this;
}


template <class TELEM>
TELEM& TContainer<TELEM>::operator[](int index)
{
        if (index < 0 || index >= count)
        {
            throw cntINDOUTOFRANGE;//get problem index
        }
    return elem[index]; // type value
}

template <class TELEM>

TELEM& TContainer<TELEM>::operator[](const TELEM& obj)

{
    int index;
    if ((index = _find(obj)) == -1)//implement the find method
    {
        throw cntVALOUTOFRANGE;//get problem value
    }
    return elements[index];   //type value
}
