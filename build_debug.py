import os
import shutil
import subprocess
	
def main():
	print("Building debug version of Vaultage.")

	# First make debug directory if it does exist
	if os.path.exists("build") == False:
		os.mkdir("build")

	if os.path.exists("build/debug") == False:
		os.mkdir("build/debug")
	
	# Create cmake files in debug directory
	os.chdir("build/debug")
	subprocess.run(["cmake", "-DCMAKE_BUILD_TYPE=Debug", "../.."])
	
	# Compile code
	subprocess.run(["cmake", "--build", ".", "--parallel"])

	# Move compile_commands file for use with clangd
	if os.path.exists("compile_commands.json"):
		shutil.copyfile("compile_commands.json", "../../compile_commands.json")
	
if __name__ == "__main__":
	main()