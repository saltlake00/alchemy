#include <vector>
#include <iostream>
#include <string>

class PotionRecipe
{
public:
	PotionRecipe(const std::string& potionName, const std::string& coreIngredient)
	{
		PotionName_ = potionName;
		CoreIngredient_ = coreIngredient;
	}

	const std::string& getPotionName() const
	{
		return PotionName_;
	}

	const std::string& getCoreIngredient() const
	{
		return CoreIngredient_;
	}

private:
	std::string PotionName_;
	std::string CoreIngredient_;
};

class AlchemyWorkshop
{
public:
	void AddRecipe(const std::string& potionName, const std::string& coreIngredient)
	{
		recipes_.push_back(PotionRecipe(potionName, coreIngredient));
	}

	void DisplayAllRecipes() const
	{
		for (const PotionRecipe& recipe : recipes_)
			std::cout << recipe.getPotionName() << " : " << recipe.getCoreIngredient() << std::endl;
	}

	PotionRecipe SearchRecipeByName(const std::string& name) const
	{
		for (const PotionRecipe& recipe : recipes_)
		{
			if (recipe.getPotionName() == name)
				return recipe;
		}
		return PotionRecipe("NONE", "NONE");
	}

	std::vector<PotionRecipe> SearchRecipeByIngredient(const std::string& ingredient) const
	{
		std::vector<PotionRecipe> ret;
		for (const PotionRecipe& recipe : recipes_)
		{
			if (recipe.getCoreIngredient() == ingredient)
				ret.push_back(recipe);
		}
		return ret;
	}

private:
	std::vector<PotionRecipe> recipes_;
};

int main()
{
	AlchemyWorkshop workshop;
	workshop.AddRecipe("Healing Potion", "Herb");
	workshop.AddRecipe("Mana Potion", "Magic Water");
	workshop.AddRecipe("Stamina Potion", "Herb");
	workshop.AddRecipe("Fire REsistance Potion", "Herb");

	workshop.DisplayAllRecipes();

	PotionRecipe recipe = workshop.SearchRecipeByName("Mana Potion");
	std::cout << "검색된 레시피: " << recipe.getPotionName() << std::endl;;

	std::vector<PotionRecipe> herbRecipes = workshop.SearchRecipeByIngredient("Herb");

	std::cout << "Herb를 사용하는 레시피 수: " << herbRecipes.size() << std::endl;

	return 0;
}