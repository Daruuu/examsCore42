#include "searchable_bag.hpp"

class set
{
	private:
		searchable_bag& bag;

	//	OCR
		set();
		set(const set& other);
		set& operator=(const set& other);

	public:
		set(searchable_bag& s_bag);	// faltaba implementar
		const searchable_bag& get_bag();
		bool has(int value) const;
		//	override de bag
		void insert(int value);
		void insert(int *arr, int size);
		void print() const;
		void clear();
		~set();
};
