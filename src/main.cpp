#include "sparkleTemplate.hpp"
#include <vulkan/vulkan.hpp>

int main()
{
	VkInstanceCreateInfo createInfo = {};
	createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;

	VkInstance instance;
	if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS) {
		// Gérer l'erreur
		return 0;
	}

	uint32_t apiVersion = 0;
	if (vkEnumerateInstanceVersion(&apiVersion) != VK_SUCCESS) {
		// Gérer l'erreur
		return 0;
	}

	uint32_t major = VK_VERSION_MAJOR(apiVersion);
	uint32_t minor = VK_VERSION_MINOR(apiVersion);
	uint32_t patch = VK_VERSION_PATCH(apiVersion);

	std::cout << "Vulkan API Version: " << major << "." << minor << "." << patch << std::endl;

	vkDestroyInstance(instance, nullptr);
	return (0);
};