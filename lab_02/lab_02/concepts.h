#pragma once

#include <concepts>
#include <cmath>

// CONTAINER + TYPE U CONCEPTS
template <typename C>
concept Container = requires(C cont)
{
	typename C::value_type;
	typename C::iterator;
	typename C::const_iterator;
	typename C::size_type;

	{ cont.begin() } noexcept -> std::same_as<typename C::iterator>;
	{ cont.end() } noexcept -> std::same_as<typename C::iterator>;
	{ cont.cbegin() } noexcept -> std::same_as<typename C::const_iterator>;
	{ cont.cend() } noexcept -> std::same_as<typename C::const_iterator>;
	{ cont.size() } noexcept -> std::same_as<typename C::size_type>;
};

template <typename C, typename V>
concept Convertible = requires(const C & cont)
{
	Vector<V>(cont);
};

template<typename T, typename U>
concept ConvertibleTo = requires(T lh, U rh)
{
	{ lh } -> std::convertible_to<U>;
};

template <typename C, typename T>
concept ConvertibleContainer = requires(const C & cont) {
	requires Container<C>;
	requires Convertible<typename C::value_type, T>;
	requires ConvertibleTo<typename C::value_type, T>;
};







template <typename U, typename T>
concept ConvertibleToT = requires(const U&)
{
	requires ConvertibleTo<T, U>;
};



template <typename T, typename U>
concept Dividable = requires(T lh, U rh)
{
	{ lh / rh } -> std::convertible_to<U>;
};

template <typename T, typename U>
concept Dividing = requires(T lh, U rh)
{
	{ rh / lh } -> std::convertible_to<U>;
	{ lh == 0 } -> std::convertible_to<bool>;
	{ rh* lh } -> std::convertible_to<U>;
	{ rh + lh } -> std::convertible_to<U>;
};

template <typename T, typename U>
concept SomehowDividing = requires(T lh, U rh)
{
	{ rh / lh } -> std::convertible_to<U>;
	{ rh* lh } -> std::convertible_to<U>;
	{ rh + lh } -> std::convertible_to<U>;

};

template<typename T, typename U>
concept Equatable = requires(T a, U b)
{
	{ a == b } -> std::convertible_to<bool>;
	{ a != b } -> std::convertible_to<bool>;
	{ b == a } -> std::convertible_to<bool>;
	{ b != a } -> std::convertible_to<bool>;
};

template <typename T, typename U>
concept SomehowSubstracting = requires(T lh, U rh)
{
	{ rh - lh };
};

template<typename T, typename U>
concept Summing =
	requires(T lh, U rh)
{
	{ rh + lh } -> std::convertible_to<U>;
};

template<typename T, typename U>
concept Summable =
	requires(T lh, U rh)
{
	{ lh + rh } -> std::convertible_to<U>;
};

template<typename T, typename U>
concept SomehowSumming =
	requires(T lh, U rh)
{
	{ rh + lh };
};

template<typename T, typename U>
concept SomehowSummable =
	requires(T lh, U rh)
{
	{ lh + rh };
};

template <typename T, typename U>
concept SomehowMultable = requires(T lh, U rh) {
	{ lh* rh };
};

template <typename U, typename T>
concept MutableWithT = requires(const U&)
{
	requires SomehowMultable<T, U>;
	requires ConvertibleTo<T, U>;
};

template <typename U, typename T>
concept DividableWithT = requires(const U&)
{
	requires Dividable<T, U>;
	requires ConvertibleTo<T, U>;
};

template <typename U, typename T>
concept SummableWithT = requires(const U&)
{
	requires SomehowSummable<T, U>;
	requires ConvertibleTo<T, U>;
};

template <typename U, typename T>
concept SubtractingWithT = requires(const U&)
{
	requires SomehowSubstracting<T, U>;
	requires ConvertibleTo<T, U>;
};

template <typename U, typename T>
concept CanWorkWithT = requires(const U&)
{
	requires (ConvertibleToT<U, T> || ConvertibleToT<T, U>) && MutableWithT<U, T>&& DividableWithT<U, T>&& SummableWithT<U, T>&& SubtractingWithT<U, T>;
};

template <typename U, typename T>
concept WorkableAndConvertibleToT = requires(const U&)
{
	requires ConvertibleTo<U, T>;
	requires CanWorkWithT<T, U>;
};

template <typename T, typename U>
concept DerivedFrom = std::is_base_of<U, T>::value;




// TYPE T CONCEPTS

template <typename T>
concept Numeric = std::is_arithmetic_v<T> || requires(T a) {
	{ sqrt(a) };
};

template<typename T>
concept SelfEquatable = requires(T a, T b)
{
	{ a == b } -> std::convertible_to<bool>;
	{ a != b } -> std::convertible_to<bool>;
};

template<typename T>
concept Indextable = std::same_as<T, int> || std::same_as<T, std::size_t>;

template<typename T>
concept Invertible = requires (T a)
{
	{ -a };
};

template<typename T, typename U>
concept SameAs = std::same_as<T, U>;

template <typename T, typename U>
concept Substracting = requires(T lh, U rh)
{
	{ rh - lh } -> std::convertible_to<U>;
};

template <typename T, typename U>
concept Substractable = requires(T lh, U rh)
{
	{ lh - rh } -> std::convertible_to<U>;
};

template <typename T>
concept SelfSubstractable = requires(T lh, T rh)
{
	{ lh - rh } -> std::same_as<T>;
	
};

template <typename T>
concept SelfSubstractableEqual = requires(T lh, T rh)
{
	{ lh -= rh } -> std::same_as<T&>;
};

template <typename T>
concept SelfMultable = requires(T a, T b) {
	{ a * b } -> std::same_as<T>;
	{ a *= b};
};

template <typename T>
concept SelfMultableEqual = requires(T a, T b) {
	{ a *= b } -> std::same_as<T>;
};

template <typename T>
concept SelfAddable = requires(T a, T b) {
	{ a + b } -> std::same_as<T>;
};

template <typename T>
concept SelfAddableEqual = requires(T a, T b) {
	{ a += b } -> std::same_as<T&>;
};

template <typename T>
concept SelfAssignmentable = requires(T a, T b) {
	{ a = b };
};

template <typename T>
concept SelfDividable = requires(T a, T b) {
	{ a / b } -> std::same_as<T>;
	{ a /= b };
};

template <typename T>
concept SelfDividableEqual = requires(T a, T b) {
	{ a /= b } -> std::same_as<T>;
};

template <typename T>
concept SelfComparable = requires(T a, T b) {
	{ a < b } -> std::same_as<bool>;
	{ a <= b } -> std::same_as<bool>;
	{ a > b } -> std::same_as<bool>;
	{ a >= b } -> std::same_as<bool>;
	{ a == b } -> std::same_as<bool>;
	{ a != b } -> std::same_as<bool>;
};

template <typename T>
concept Incr = requires(T a)
{
	{ ++a };
	{ a++ };
};

template <typename T>
concept Decr = requires(T a)
{
	{ --a };
	{ a-- };
};

template <typename T>
concept ValidType = Numeric<T> && SelfComparable<T> && SelfAddable<T> && SelfMultable<T> && SelfAddableEqual<T> && SelfAssignmentable<T> && SelfDividable<T> && SelfSubstractableEqual<T> && Invertible<T> && Incr<T> && Decr<T>;




// Iterator Concepts

template <typename I>
concept RandomAccessible = requires(I iter, typename I::difference_type n)
{
	{ iter + n } -> std::same_as<I>;
	{ iter - n } -> std::same_as<I>;
	{ iter += n } -> std::same_as<I&>;
	{ iter -= n } -> std::same_as<I&>;
	{ iter[n] } -> std::same_as<typename I::reference>;
};

template <typename I>
concept Incrementable = requires(I iter)
{
	{ ++iter } -> std::same_as<I&>;
	{ iter++ } -> std::same_as<I>;
};

template <typename I>
concept Decrementable = requires(I iter)
{
	{ --iter } -> std::same_as<I&>;
	{ iter-- } -> std::same_as<I>;
};

template <typename I>
concept InputIter = requires(I iter)
{
	{ *iter } -> std::convertible_to<typename I::value_type>;
	{ iter } -> std::convertible_to<bool>;
	{ iter++ };
	{ ++iter };
	{ *iter++ };
};

template <typename I>
concept Accessible = requires(I iter)
{
	{ *iter } -> std::convertible_to<typename I::value_type>;
};

template <typename I>
concept Distance = requires(I it1, I it2)
{
	{ it2 - it1 } -> std::convertible_to<typename I::difference_type>;
};

template <typename I>
concept Addable = requires(I it1, I it2)
{
	{ it1 + it2 } -> std::convertible_to<I>;
};

template <typename I>
concept CIterator = requires(I iter)
{
	typename I::iterator_category;
	typename I::value_type;
	typename I::difference_type;
	typename I::pointer;
	typename I::reference;
} && InputIter<I> && Distance<I>;

template <typename I, typename T>
concept ConvertibleIterator = requires(I iter)
{
	requires CIterator<I>;
	requires Convertible<typename I::value_type, T>;
};

