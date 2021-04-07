#include "resources.h"
#include <string>


class UBlock
{
	public:
	UBlock() {};
	~UBlock() {};

	ResAmount res(int index);
	/**
	 * Get the total area of content in the Block
	 *
	 * @return total size
	 */
	float totalSize();
	/**
	 * Check the size available to add
	 *
	 * @return size available
	 */
	float availableSize();
	/**
	 * Find the index of the content of given res
	 *
	 * @return index of the content, -1 if not found
	 */
	int findRes(const Res* res);
	/**
	 * Find the content with the smaller amount
	 * 
	 * @return index for the smaller content
	 */
	int findSmaller();
	/**
	 * Add a resource to the content list if a slot is available or the resource is already present
	 * 
	 * @return 
	 */
	float addRes(const Res* res, float amount);
	float addRes(const Res *res, float amount, bool force);
	float removeRes(const Res *res, float amount);
	static const int maxSlots = 5;


	private:

	float maxSize = 1000;
	ResAmount content[maxSlots];
};

