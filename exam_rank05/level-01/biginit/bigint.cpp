#include <vector>
#include "bigint.hpp"

// ============================================================================
// CONSTRUCTORES Y FUNCIONES AUXILIARES
// ============================================================================

/*
 * Constructor por defecto
 * Crea un bigint con valor 0
 */
bigint::bigint()
{
	digits_.push_back(0);
}

/*
 * Convierte un unsigned long a bigint
 * Extrae cada dígito usando módulo 10 y división
 * Los dígitos se guardan en orden INVERSO para facilitar operaciones
 * Ejemplo: 1337 -> [7, 3, 3, 1]
 */
void bigint::from_unsigned_long(unsigned long n)
{
	digits_.clear();
	
	// Caso especial: el número es 0
	if (n == 0)
	{
		digits_.push_back(0);
		return ;
	}
	
	// Extraer dígitos de derecha a izquierda
	while (n > 0)
	{
		digits_.push_back(static_cast<unsigned char>(n % 10));
		n /= 10;
	}
}

/*
 * Constructor desde unsigned long
 * Convierte un número normal a bigint
 */
bigint::bigint(unsigned long n)
{
	from_unsigned_long(n);
}

/*
 * Elimina ceros a la izquierda (que están al final del vector)
 * Ejemplo: [2, 4, 0, 0] -> [2, 4] (que representa 42, no 0042)
 * IMPORTANTE: Siempre deja al menos un dígito (para representar 0)
 */
void bigint::normalize()
{
	while (digits_.size() > 1 && digits_.back() == 0)
		digits_.pop_back();
}

/*
 * Constructor de copia
 * Crea una copia exacta de otro bigint
 * Usa lista de inicialización para copiar el vector
 */
bigint::bigint(const bigint& other) : digits_(other.digits_)
{
}

// ============================================================================
// OPERADOR DE ASIGNACIÓN
// ============================================================================

/*
 * Operador de asignación
 * Copia el valor de otro bigint a este
 * Verifica auto-asignación (a = a) para evitar problemas
 * Retorna *this para permitir encadenamiento: a = b = c
 */
bigint& bigint::operator=(const bigint& other)
{
	if (this != &other)
		digits_ = other.digits_;
	return *this;
}

// ============================================================================
// OPERADOR DE SALIDA (STREAM)
// ============================================================================

/*
 * Operador de salida para imprimir el bigint
 * Imprime los dígitos en orden INVERSO (del final al principio del vector)
 * porque están almacenados al revés
 * Ejemplo: vector [7, 3, 3, 1] se imprime como "1337"
 */
std::ostream& operator<<(std::ostream& os, const bigint& b)
{
	// Caso especial: vector vacío (no debería pasar, pero por seguridad)
	if (b.digits_.empty())
		return os << "0";

	// Imprimir dígitos de atrás hacia adelante
	for (int i = (int)b.digits_.size() - 1; i >= 0; --i)
		os << (int) b.digits_[i];
	return os;
}

// ============================================================================
// OPERADORES DE COMPARACIÓN
// ============================================================================

/*
 * Operador de igualdad
 * Dos bigints son iguales si tienen exactamente los mismos dígitos
 * El vector ya compara elemento por elemento
 */
bool bigint::operator==(const bigint& other) const
{
	return digits_ == other.digits_;
}

/*
 * Operador de desigualdad
 * Simplemente niega el operador ==
 */
bool bigint::operator!=(const bigint& other) const
{
	return !(*this == other);
}

/*
 * Operador 'menor que' (<)
 * Algoritmo:
 * 1. Si tienen diferente cantidad de dígitos, el que tiene menos es menor
 *    Ejemplo: 99 (2 dígitos) < 100 (3 dígitos)
 * 2. Si tienen igual cantidad, comparar dígito por dígito de izquierda a derecha
 *    (que es de derecha a izquierda en nuestro vector invertido)
 */
bool bigint::operator<(const bigint& other) const
{
	// Comparar tamaños primero
	if (digits_.size() != other.digits_.size())
		return ( digits_.size() < other.digits_.size() );

	// Mismo tamaño: comparar dígito por dígito desde el más significativo
	for (int i = (int)digits_.size() - 1; i >= 0; --i)
	{
		if (digits_[i] != other.digits_[i])
			return digits_[i] < other.digits_[i];
	}
	
	// Son iguales, por lo tanto no es menor
	return false;
}

/*
 * Operador 'mayor que' (>)
 * 'a > b' es equivalente a 'b < a'
 */
bool bigint::operator>(const bigint& other) const
{
	return other < *this;
}

/*
 * Operador menor o igual (<=)
 * 'a <= b' es verdadero si 'a < b' O 'a == b'
 */
bool bigint::operator<=(const bigint& other) const
{
	return ( *this < other || *this == other );
}

/*
 * Operador mayor o igual (>=)
 * a >= b es equivalente a !(a < b)
 */
bool bigint::operator>=(const bigint& other) const
{
	return !(*this < other);
}

// ============================================================================
// OPERADORES DE SUMA
// ============================================================================

/*
 * Suma de bigint + unsigned long
 * Convierte el unsigned long a bigint y usa el operador + de bigint
 */
bigint bigint::operator+(unsigned long n) const
{
	return ( *this + bigint(n) );
}

/*
 * Suma y asigna un unsigned long
 * Ejemplo: a += 5
 */
bigint& bigint::operator+=(unsigned long n)
{
	*this = *this + n;
	return *this;
}

/*
 * Suma de dos bigints
 * Usa el algoritmo clásico de suma con acarreo (carry)
 * 
 * Ejemplo visual (con dígitos normales):
 *     1337
 *   +   42
 *   ------
 *     1379
 * 
 * En nuestro caso, sumamos de izquierda a derecha en el vector
 * porque los dígitos están invertidos:
 * [7,3,3,1] + [2,4] = [9,7,3,1]
 */
bigint bigint::operator+(const bigint& other) const
{
	bigint res;
	res.digits_.clear();
	
	// Obtener el tamaño del número más grande
	size_t n = std::max(digits_.size(), other.digits_.size());
	
	unsigned char carry = 0;  // Acarreo (0 o 1)
	
	// Iterar mientras haya dígitos o carry pendiente
	for (size_t i = 0; i < n || carry; ++i)
	{
		unsigned int sum = carry;
		
		// Sumar dígito de este número si existe
		if (i < digits_.size())
			sum += digits_[i];
		
		// Sumar dígito del otro número si existe
		if (i < other.digits_.size())
			sum += other.digits_[i];
		
		// Guardar el dígito resultado (sum % 10)
		res.digits_.push_back(sum % 10);
		
		// Calcular nuevo carry (sum / 10)
		carry = sum / 10;
	}
	
	res.normalize();  // Eliminar ceros a la izquierda si hay
	return res;
}

/*
 * Suma y asigna otro bigint
 * Ejemplo: a += b
 */
bigint& bigint::operator+=(const bigint& other)
{
	*this = *this + other;
	return *this;
}

// ============================================================================
// OPERADORES DE INCREMENTO
// ============================================================================

/*
 * Pre-incremento: ++a
 * Incrementa el valor y retorna la referencia al objeto modificado
 * Permite encadenar: ++(++a)
 */
bigint& bigint::operator++()
{
	*this += 1;
	return *this;
}

/*
 * Post-incremento: a++
 * Retorna el valor ANTERIOR y luego incrementa
 * El parámetro int es solo para diferenciar del pre-incremento
 * 
 * Ejemplo:
 *   a = 5
 *   b = a++  -> b = 5, a = 6
 */
bigint bigint::operator++(int)
{
	bigint temp(*this);  // Guardar valor actual
	++(*this);           // Incrementar usando pre-incremento
	return temp;         // Retornar valor anterior
}

// ============================================================================
// OPERADORES DE DIGIT SHIFT IZQUIERDO (<<)
// ============================================================================

/*
 * Shift izquierdo: multiplica por 10^n
 * Equivale a añadir n ceros a la derecha del número
 * 
 * Ejemplo: 42 << 3 = 42000
 * 
 * En nuestro vector invertido:
 * [2, 4] << 3 = [0, 0, 0, 2, 4]
 * 
 * Insertamos n ceros al PRINCIPIO del vector (que es el final del número)
 */
bigint bigint::operator<<(unsigned long n) const
{
	bigint res(*this);
	
	// Caso especial: 0 << n = 0
	if (res.digits_.size() == 1 && res.digits_[0] == 0)
		return res;
	
	// Insertar n ceros al principio del vector (final del número)
	for (unsigned long i = 0; i < n; ++i)
		res.digits_.insert(res.digits_.begin(), 0);
	
	return res;
}

/*
 * Shift izquierdo con asignación
 * Ejemplo: a <<= 3
 */
bigint& bigint::operator<<=(unsigned long n)
{
	*this = *this << n;
	return *this;
}

// ============================================================================
// OPERADORES DE DIGIT SHIFT DERECHO (>>)
// ============================================================================

/*
 * Shift derecho: divide por 10^n (elimina n dígitos de la derecha)
 * 
 * Ejemplo: 1337 >> 2 = 13
 * 
 * En nuestro vector invertido:
 * [7, 3, 3, 1] >> 2 = [3, 1]
 * 
 * Eliminamos n elementos del PRINCIPIO del vector (que son los dígitos
 * menos significativos del número)
 * 
 * Acepta bigint como parámetro porque el main hace: d >>= (const bigint)2
 */
bigint bigint::operator>>(const bigint& other) const
{
	bigint res(*this);
	
	// Convertir el bigint 'other' a unsigned long
	// Reconstruir el número desde el vector invertido
	unsigned long shift_amount = 0;
	unsigned long multiplier = 1;
	
	for (size_t i = 0; i < other.digits_.size(); ++i)
	{
		shift_amount += other.digits_[i] * multiplier;
		multiplier *= 10;
	}
	
	// Si shift_amount >= cantidad de dígitos, el resultado es 0
	if (shift_amount >= res.digits_.size())
	{
		res.digits_.clear();
		res.digits_.push_back(0);
	}
	else
	{
		// Eliminar shift_amount dígitos del principio del vector
		for (unsigned long i = 0; i < shift_amount; ++i)
			res.digits_.erase(res.digits_.begin());
		res.normalize();
	}
	
	return res;
}

/*
 * Shift derecho con asignación
 * Ejemplo: a >>= bigint(2)
 */
bigint& bigint::operator>>=(const bigint& other)
{
	*this = *this >> other;
	return *this;
}
