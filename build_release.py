import os
import shutil
import subprocess
	
def main():
	print("Building release version of Vaultage.")

	# First make release directory if it does exist
	if os.path.exists("build") == False:
		os.mkdir("build")

	if os.path.exists("build/release") == False:
		os.mkdir("build/release")
	
	# Create cmake files in release directory
	os.chdir("build/release")
	subprocess.run(["cmake", "-DCMAKE_BUILD_TYPE=Release", "../.."])
	
	# Compile code
	subprocess.run(["cmake", "--build", ".", "--parallel"])

	# Move compile_commands file for use with clangd
	if os.path.exists("compile_commands.json"):
		shutil.copyfile("compile_commands.json", "../../compile_commands.json")
	
if __name__ == "__main__":
	main()