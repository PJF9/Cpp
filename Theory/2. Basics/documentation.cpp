/**
 * Sum numbers in a vector.
 *
 * This sum is the arithmetic sum, not some other kind of sum that only
 * mathematicians have heard of.
 *
 * @param values Container whose values are summed.
 * @return sum of `values`, or 0.0 if `values` is empty.
 */

//! Before the method or class we want to document

/**
 * Storage for arbitrary data with log(N) lookup.
 *
 * ...
 *
 * @tparam T the type of data stored in the table
 * @tparam ComparatorT callable defining a strict weak ordering for objects
 *     of type `T`. Its `operator()` must accept two `T` and return `true`
 *     if and only if the first argument comes before the second. It must
 *     not throw exceptions.
 */

//! This is the template parameter
/**
 * @tparam T, U the types of the pair components
 */

/*
    @param should be given with the [in], [out], or [in, out] tag if the function 
    method contains any output parameters. The [in] tag is optional if all parameters
    are input, even if other functions or methods in the same class or package use 
    output parameters.
*/

/**
 * Compute mean and standard deviation for a collection of data.
 *
 * @param[out] mean the mean of `data`, or `NaN` if `data` is empty
 * @param[out] stdDev the unbiased (sample) standard deviation, or `NaN`
 *     if `data` contains fewer than 2 elements
 * @param[in] data the data to analyze
 */

/**
 * @param x, y the coordinates where the function is evaluated
 */


/**
 * Write an image to disk.
 *
 * @exception lsst::pex::exceptions::IoError Thrown if `fileName` could not be
 *     written to.
 */


/*
    Whether or not there are any @throws tags for specific exceptions, a function or 
    method should have an @exceptsafe tag. The description following the tag should 
    describe the level of exception safety provided by the function or method.

    The following terms may be used for brevity:

    no-throw
        The function is guaranteed to always return without throwing an exception.
    strong
        If the function throws an exception, the program will be in the same state 
        as before the call; i.e., failed calls have no side effects.
    basic
        If the function throws an exception, the program will be in a valid state, 
        but not necessarily a predictable one. No memory, file descriptors, locks, or 
        other resources will be leaked.
    none
        If the function throws an exception, objects may be corrupted and unsafe to use, 
        or resources may be leaked. 
*/

/**
 * Image associated with this map.
 *
 * @exceptsafe Shall not throw exceptions.
 */

/**
 * Compute an element-wise cosine.
 *
 * @see sin
 * @see tan
 * @see [numpy.vectorize](https://docs.scipy.org/doc/numpy/reference/generated/numpy.vectorize.html)
 */


/**
 * Read an image from disk.
 *
 * @param fileName the file to read. Must be either absolute or relative to
 *     the program working directory.
 *
 * @return the image stored in `fileName`. If the image on disk does not
 *     have `double` pixels, they will be cast to `double`.
 *
 * @exception IoError Thrown if `fileName` does not exist or is not readable.
 *
 * @exceptsafe Strong exception guarantee.
 */


/**
 * Sum numbers in a vector.
 *
 * @param values Container whose values are summed.
 * @return sum of `values`, or 0.0 if `values` is empty.
 *
 * @exceptsafe This function does not throw exceptions.
 */
/**
 * Sum numbers in an array.
 *
 * @overload
 */