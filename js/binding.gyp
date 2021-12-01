{
  "variables": {
    "dll_files": ["./x64/SDL2.dll"]
  },
  "targets": [
    {
      "include_dirs": ["../src/include"],
      "target_name": "nodesdl",
      "sources": [
        "../cpp/main.cpp",
        "../cpp/classes/Rect.cpp",
        "../cpp/classes/Clock.cpp",
        "../cpp/classes/keyhandler.cpp",
      ],
      "libraries": [
        "<(module_root_dir)/x64/SDL2main.lib", "<(module_root_dir)/x64/SDL2.lib"
      ],
      "copies": [
        {
          "destination": "<(module_root_dir)/build/Release/",
          "files": ["<(module_root_dir)/x64/SDL2.dll", "<(module_root_dir)/x64/SDL2main.lib", "<(module_root_dir)/x64/SDL2.lib"]
        }
      ]
    }
  ],
}

# ==================================================== SAMPLE binding.gyp file ====================================================
# {
#   "targets": [
#     {
#       "target_name": "addon",
#       "sources": [
#         "main.cc"
#       ],
#       "conditions": [
#         [
#           "OS==\"win\"",
#           {
#             "libraries": [
#               "<(module_root_dir)/tobii/lib/x64/tobii_interaction_lib.lib",
#               "<(module_root_dir)/tobii/lib/x64/tobii_stream_engine.lib"
#             ],
#             "include_dirs": [
#               "<(module_root_dir)/tobii/include"
#             ],
#             "copies": [
#               {
#                 "destination": "<(module_root_dir)/build/Release/",
#                 "files": [
#                   "<(module_root_dir)/tobii/lib/x64/tobii_interaction_lib.dll",
#                   "<(module_root_dir)/tobii/lib/x64/tobii_stream_engine.dll"
#                 ]
#               }
#             ]
#           }
#         ]
#       ]
#     }
#   ]
# }
