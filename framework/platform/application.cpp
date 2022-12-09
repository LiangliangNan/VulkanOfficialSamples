/* Copyright (c) 2019-2021, Arm Limited and Contributors
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 the "License";
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "application.h"

#include <iostream>

//#include "common/logging.h"
//#include "platform/platform.h"


namespace vkb {

std::string Application::external_storage_directory = "";

std::string Application::temp_directory = "";

    Application::Application() :
            name{"Sample Name"} {
	    auto win = Platform::create_window(this);
	    window = std::move(win);
    }

    bool Application::prepare() {
        return true;
    }

    void Application::main_loop() {
	    while (!window->should_close())
	    {
		    try
		    {

			    auto delta_time = static_cast<float>(timer.tick<Timer::Seconds>());

//			    if (focused)
			    {
//				    on_update(delta_time);

//				    if (fixed_simulation_fps)
//				    {
//					    delta_time = simulation_frame_time;
//				    }

				    update(delta_time);
			    }

			    window->process_events();
		    }
		    catch (std::exception &e)
		    {
			    LOGE("Error Message: {}", e.what());
			    LOGE("Failed when running application {}", get_name());
//			    on_app_error(active_app->get_name());
		    }
	    }
    }

    void Application::finish() {
    }

    bool Application::resize(const uint32_t /*width*/, const uint32_t /*height*/) {
        return true;
    }

    void Application::input_event(const InputEvent &input_event) {
    }

    void Application::update(float delta_time) {
        fps = 1.0f / delta_time;
        frame_time = delta_time * 1000.0f;
    }

    const std::string &Application::get_name() const {
        return name;
    }

    void Application::set_name(const std::string &name_) {
        name = name_;
    }

}
