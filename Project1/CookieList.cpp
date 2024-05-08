/*
	Guild, Ryan (team leader)
	Tran, Lily
	Nguyen, Jordan
	Aljaffan, Maha

	CS A250
	Project (Part B)
*/

#include "CookieList.h"

#include <iostream>

using namespace std;

void CookieList::addCookie(const Cookie& newCookie)
{
	Node* newNode = new Node(newCookie, nullptr);

	if (count == 0) 
	{
		first = newNode;
		last = newNode;
	}
	else {
		last->setNext(newNode);
		last = newNode;
	}
	count++;
}

void CookieList::addCookie(const std::string& name, size_t calories,
		size_t servings, const std::set<std::string>& ingredients)
{
	Cookie newCookie(name, calories, servings, ingredients);
	Node* newNode = new Node(newCookie, nullptr);

	if (count == 0)
	{
		first = newNode;
		last = newNode;
	}else
	{
		last->setNext(newNode);
		last = newNode;
	}
	count++;
}

void CookieList::clearList()
{
	Node* current = first;
	while (current != nullptr) 
	{
		Node* next = current->getNext();
		delete current;
		current = next;
	}
	first = nullptr;
	last = nullptr;
	count = 0;
}

size_t CookieList::getCount() const 
{
	return count;
}

bool CookieList::isEmpty() const 
{
	return (count == 0);
}

bool CookieList::searchCookie(const std::string& cookieName) const
{
	Node* current = first;
	while (current != nullptr) {
		if (current->getCookie().getName() == cookieName) 
		{
			return true;
		}
		current = current->getNext();
	}
	return false;
}

void CookieList::printAllCookies() const
{
	cout << "Cookie Names: " << endl;

	if (this->isEmpty())
	{
		cout << "The list is empty.";
	}
	else
	{
		Node* current = first;
		
		while (current != nullptr)
		{
			cout << current->getCookie().getName() << endl;
			current = current->getNext();
		}
	}
	
}

//CookieList::CookieList(const CookieList& other)
//{
//	Node* current = other.first;
//	while (current != nullptr) 
//	{
//		const Cookie& cookie = current->getCookie();
//		addCookie(cookie.getName(), cookie.getCalories(), 
//				cookie.getServings(), cookie.getIngredients());
//		current = current->getNext();
//	}
//
//}
CookieList::CookieList(const CookieList& other)
{

	if (this->isEmpty())
	{
		clearList();
	}

	Node* current = other.first;
	first = current;
	while (current != nullptr)
	{
		const Cookie& aCookie = current->getCookie();
		this->addCookie(aCookie);
		current = current->getNext();
	}
	count = other.count;
	Node* newLast = other.last;
	last = newLast;
}


CookieList& CookieList::operator=(const CookieList& cookieToAssign)
{
	if (&cookieToAssign != this)
	{
		clearList();
		Node* current = cookieToAssign.first;
		while (current != nullptr)
		{
			addCookie(current->getCookie());
			current = current->getNext();
		}
	}
	else
		cerr << "Attempted assignment to itself.";
	
	return *this;
}

CookieList::~CookieList()
{
	clearList();
}
