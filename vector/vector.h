#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H

#include <iostream>
 #include <cstddef>
#include <limits>

static const size_t MAX_SIZE=std::numeric_limits<size_t>::max();
template<typename T>
class Vector
{
public:
	Vector();
    explicit Vector(size_t size ,const T& val=T(0));//default val to initialize vector
    Vector(const Vector& other);
    ~Vector();
	Vector& operator=(const Vector& other);
    size_t size()const;
    size_t max_size()const;
    size_t capacity()const;
    void resize(size_t size,const T& val=T(0));//resize memory in use and initialize the extra objects with default val
    bool empty()const;
    void reserve (size_t n);//reserve capacity
    T& operator[](size_t index);
	const T& operator[](size_t index)const;
	T& at(size_t index);
	const T& at(size_t index)const;
	T& front();
	const T& front()const;
	T& back();
	const T& back()const;
	T* data();
	const T* data()const;
	void assign(size_t size, const T& val);//default val to initialize vector
    void push_back(const T& val);
	void pop_back();
	void insert(size_t position, const T& val, size_t n=1);
	void erase(size_t position);
	void swap (Vector& vector);
	void clear();

private:
    T* m_vector;
    size_t m_size;
    size_t m_capacity;
};

template<typename T>
inline Vector<T>::Vector():m_vector(new T[10]), m_size(0), m_capacity(0){}

template<typename T>
Vector<T>::Vector(size_t size, const T& val):m_vector(new T[size]),m_size(size),m_capacity(size)
{
    for(size_t i = 0;i < size;++i)
        m_vector[i] = val;
}

template<typename T>
Vector<T>::Vector(const Vector& other):m_vector(new T[other.m_capacity]),m_size(other.m_size),m_capacity(other.m_capacity)
{
    
    for(size_t i = 0;i < other.m_size;++i)
        m_vector[i] = other.m_vector[i];
}

template<typename T>
Vector<T>::~Vector()
{
    delete []m_vector;
    m_vector = NULL;
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector& other)
{
	if (m_capacity != other.m_capacity)
	{
		T* original=m_vector;
		m_vector=new T[other.m_capacity];
		delete[] original;
	}
	for(size_t i=0;i<other.m_size;i++)
	{
		m_vector[i]=other.m_vector[i];
	}
	m_size=other.m_size;
	m_capacity=other.m_capacity;
	return *this;
}

template<typename T>
size_t Vector<T>::size()const{
    return m_size;
}

template<typename T>
size_t Vector<T>::max_size()const{
    return MAX_SIZE;
}

template<typename T>
void Vector<T>::resize(size_t size,const T& val)
{
	if(size>m_size)
	{
		reserve(size);
		for(size_t i=m_size;i<size;i++)
			m_vector[i]=val;
	}
	else
	{
		for(size_t i=size;i<m_size;i++)
		{
			m_vector[i].~T();
		}
	
	}
	m_size=size;
}

template<typename T>
size_t Vector<T>::capacity()const{
    return m_capacity;
}

template<typename T>
bool Vector<T>::empty() const {
    return m_size == 0;
}

template<typename T>
void Vector<T>::reserve(size_t capacity)
{
    
    if(capacity>m_capacity)
	{
		T* original=m_vector;
		m_vector=new T[capacity];
		for(size_t i=0;i<m_size;i++)
		{
			m_vector[i]=original[i];
		}
		delete[] original;
		m_capacity=capacity;
	}
}

template<typename T>
inline T& Vector<T>::operator[](size_t index)
{
	return m_vector[index];
}
template<typename T>
inline const T& Vector<T>::operator[](size_t index)const
{
	return m_vector[index];
}
template<typename T>
inline T& Vector<T>::at(size_t index)
{
	if(index>=m_size)
		throw std::out_of_range("index is out of range");
	return m_vector[index];
}
template<typename T>
inline const T& Vector<T>::at(size_t index)const
{
	if(index>=m_size)
		throw std::out_of_range("index is out of range");
	return m_vector[index];
}
template<typename T>
inline T& Vector<T>::front()
{
	return m_vector[0];
}
template<typename T>
inline const T& Vector<T>::front()const
{
	return m_vector[0];
}
template<typename T>
inline T& Vector<T>::back()
{
	return m_vector[m_size-1];
}
template<typename T>
inline const T& Vector<T>::back()const
{
	return m_vector[m_size-1];
}
template<typename T>
inline T* Vector<T>::data()
{
	return m_vector;
}
template<typename T>
inline const T* Vector<T>::data()const
{
	return m_vector;
}
template<typename T>
inline void Vector<T>::assign(size_t size, const T& val)
{
	if(size<m_size)
	{
		for(size_t i=size;i<m_size;i++)
		{
			m_vector[i].~T();
		}
	}
	else
		reserve(size);
	m_size=size;
	for(size_t i=0;i<m_size;i++)
	{
		m_vector[i]=val;
	}
	
}
template<typename T>
inline void Vector<T>::push_back(const T& val)
{
	m_size++;
	if(m_size>m_capacity)
	{
		T* original=m_vector;
		m_vector=new T[m_capacity*2];
		delete[] original;
		m_capacity=m_capacity*2;
	}
	m_vector[m_size-1]=val;
}
template<typename T>
inline void Vector<T>::pop_back()
{
	m_size--;
	m_vector[m_size-1].~T();
}
template<typename T>
inline void Vector<T>::insert (size_t position, const T& val, size_t n)
{
	if(position>=m_size)
		return;
	if(n+m_size>m_capacity)
	{
		reserve((n+m_capacity)*2);
	}
	for(size_t i=m_size-1;i>=position;i--)
	{
		m_vector[i+n]=m_vector[i];
	}
	for(size_t i=position;i<position+n;i++)
	{
		m_vector[i]=val;
	}
	m_size+=n;
}
template<typename T>
inline void Vector<T>::erase(size_t position)
{
	m_size--;
	m_vector[position].~T();
	for(size_t i=position;i<m_size;i++)
		m_vector[i]=m_vector[i+1];
}
template<typename T>
inline void Vector<T>::swap (Vector& vector)
{
	Vector save(vector);
	vector=*this;
	*this=save;
}
template<typename T>
inline void Vector<T>::clear()
{
	for(size_t i=0; i<m_size; i++)
		m_vector[i].~T();
	m_size=0;
}

#endif //VECTOR_VECTOR_H
