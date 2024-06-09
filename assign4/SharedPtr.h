#ifndef SHAREDPTR_H
#define SHAREDPTR_H

#include <iostream>
#include <cassert>

template<typename ObjectType>
void Deallocator(ObjectType* ptr)
{
	std::cout << "Dealloc Object" << std::endl;
	delete ptr;
}

template<typename ObjectType>
void ArrayDeallocator(ObjectType* ptr)
{
	std::cout << "Dealloc Array" << std::endl;
	delete[] ptr;
}

template<typename T>
using DeallocatorFuncType = void (T*);

// SharedPtr
template<typename ObjectType, DeallocatorFuncType<ObjectType> Dealloc = Deallocator<ObjectType> >
class SharedPtr
{
private:
	ObjectType* m_object;
	int* m_ref_counter;

public:
	////////////////////////////////////////////
	// Constructors & destructor
	////////////////////////////////////////////

	SharedPtr() : m_object(nullptr), m_ref_counter(nullptr) { }; // Default Constructor

	explicit SharedPtr(ObjectType* object_) {
		/*
		* Constructor that gets pointer of object
		* 
		* :param ObjectType* object_: Pointer of object that will be pointed with smart pointer
		* 
		* :return void:
		*/
		if (object_ != nullptr) { // If input is not null pointer, it should be pointed.
			m_object = object_; // Point object
			m_ref_counter = new int;
			*m_ref_counter = 1; // Count up
		}

		else {
			m_object = nullptr;
			m_ref_counter = nullptr;
		}
	};

	explicit SharedPtr(const SharedPtr<ObjectType, Dealloc>& original_ptr) {
		/*
		* Copy Constructor
		* 
		* :param ObjectType* object_: Smart pointer of object that will be pointed with current smart pointer
		* 
		* :return void:
		*/
		if (original_ptr.m_object != nullptr) { // If input pointer is not null pointer, it should not be pointed.
			m_object = original_ptr.m_object; // Point object
			m_ref_counter = original_ptr.m_ref_counter; // Point reference counter
			*m_ref_counter += 1; // Count up
		}
		else { // If 
			m_object = nullptr;
			m_ref_counter = nullptr;
		}
	};

	~SharedPtr() { // destructor
		if (m_object != nullptr) { // If current pointer is not null pointer, it should not be pointed.
			(*m_ref_counter)--; // Count down
			if (*m_ref_counter == 0) { // if reference counter is 0, the allocated object will be not used
				Dealloc(m_object); // Deallocate object
				delete m_ref_counter; // Deallocate reference counter
			}
		}
	};

	////////////////////////////////////////////
	// Assignment operator
	////////////////////////////////////////////

	SharedPtr<ObjectType, Dealloc>& operator=(const SharedPtr<ObjectType, Dealloc>& original_ptr) { // assignment operator
		/*
		* Assign operator
		* 
		* :param const SharedPtr<ObjectType, Dealloc>& original_ptr: Smart pointer of object that will be pointed with current smart pointer
		* 
		* :return SharedPtr<ObjectType, Dealloc>& *this: Smart pointer itself
		*/

		if (this == &original_ptr) return *this; // Assigned itself

		if (m_object != nullptr) { // If current pointer is not null pointer, it should not be pointed.
			(*m_ref_counter)--; // Count down
			if (*m_ref_counter == 0) { // if reference counter is 0, the allocated object will be not used
				Dealloc(m_object); // Deallocate object
				delete m_ref_counter; // Deallocate reference counter
			};
		}
		
		if (original_ptr.m_object != nullptr) { // If input pointer is not null pointer, it should not be pointed.
			m_object = original_ptr.m_object; // Point object
			m_ref_counter = original_ptr.m_ref_counter; // Point reference counter
			(*m_ref_counter)++; // Count up
		}

		return *this;
	};

	// SharedPtr<ObjectType, Dealloc>& operator=(const ObjectType*) = delete;

	////////////////////////////////////////////
	// Pointer operators
	////////////////////////////////////////////

	// Supports const and non-const version of operator * and -> 
	ObjectType& operator *() { return *m_object; }
	const ObjectType& operator *() const { return *m_object; }
	ObjectType* operator ->() { return m_object; }
	const ObjectType* operator ->() const { return m_object; }
	
	////////////////////////////////////////////
	// Array element access operators
	////////////////////////////////////////////

	// Supports const and non-const version of operator []
	ObjectType& operator[](int i) { return m_object[i]; }
	const ObjectType& operator[](int i) const { return m_object[i]; }

	////////////////////////////////////////////
	// Array element access operators
	////////////////////////////////////////////
	// operator[]

	////////////////////////////////////////////
	// Type casting operators
	////////////////////////////////////////////

	// Supports const and non-const versions of typecasting operator
	operator ObjectType const* () const { return m_object; }
	operator ObjectType* () { return m_object; }

};

template<typename T>
using SharedArray = SharedPtr<T, ArrayDeallocator<T> >;

#endif
